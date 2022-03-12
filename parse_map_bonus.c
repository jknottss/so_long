/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_fd(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDWR);
	if (fd < 0)
		ft_error();
	return (fd);
}

void	map_width_and_height(t_prog **prog, char *path_to_map)
{
	int		fd;
	char	*line;

	line = NULL;
	(*prog)->height = 0;
	fd = get_fd(path_to_map);
	line = get_next_line(fd);
	if (!line)
		ft_error();
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	(*prog)->width = ft_strlen(line);
	if (!map_valid(prog, line))
		ft_error();
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		(*prog)->height++;
		if (!map_valid(prog, line))
			ft_error();
	}
	close(fd);
}

void	map_to_arr(t_prog **prog, char *path_to_map)
{
	char	**char_map;
	int		i;
	int		fd;

	i = 0;
	fd = get_fd(path_to_map);
	char_map = malloc(sizeof(char *) * (*prog)->height);
	while (i < (*prog)->height)
	{
		char_map[i] = get_next_line(fd);
		if (char_map[i][ft_strlen(char_map[i]) - 1] == '\n')
			char_map[i][ft_strlen(char_map[i]) - 1] = '\0';
		i++;
	}
	close(fd);
	if (mem_for_int_arr(prog) == -1)
		ft_error();
	map_to_int_arr(prog, char_map);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	map_valid(t_prog **prog, char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if ((*prog)->width != ft_strlen(line))
		ft_error();
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'C' \
				|| line[i] == 'P' || line[i] == 'E')
				i++;
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}
