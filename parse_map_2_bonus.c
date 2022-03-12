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

int	mem_for_int_arr(t_prog **prog)
{
	int	i;

	i = 0;
	(*prog)->map = malloc(sizeof (int *) * ((*prog)->height));
	if (!(*prog)->map)
		return (-1);
	while (i < (*prog)->height)
	{
		(*prog)->map[i] = malloc(sizeof (int) * (*prog)->width);
		if (!(*prog)->map[i])
			return (ft_free_arr(prog));
		i++;
	}
	return (1);
}

int	ft_free_arr(t_prog **prog)
{
	int	i;

	i = 0;
	while (i < (*prog)->height)
	{
		free((*prog)->map[i]);
		i++;
	}
	free((*prog)->map);
	return (-1);
}

void	free_char_arr(int height, char **char_arr)
{
	int	j;

	j = 0;
	while (j < height)
	{
		free(char_arr[j]);
		j++;
	}
	free(char_arr);
}

void	map_to_int_arr(t_prog **prog, char **char_arr_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (*prog)->height)
	{
		while (i < (*prog)->width)
		{
			if (char_arr_map[j][i] == '1')
				(*prog)->map[j][i] = wall;
			else if (char_arr_map[j][i] == '0')
				(*prog)->map[j][i] = empty;
			else if (char_arr_map[j][i] == 'C')
				(*prog)->map[j][i] = collect;
			else if (char_arr_map[j][i] == 'E')
				(*prog)->map[j][i] = ext;
			else if (char_arr_map[j][i] == 'P')
				(*prog)->map[j][i] = player;
			i++;
		}
		i = 0;
		j++;
	}
	free_char_arr((*prog)->height, char_arr_map);
}
