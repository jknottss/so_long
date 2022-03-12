/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit(t_prog **prog)
{
	(*prog)->count = 0;
	exit(0);
	return (0);
}

void	ft_init_img(t_prog **prog)
{
	int	width;

	width = 50;
	(*prog)->sprites[wall] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/wall.xpm", &width, &width);
	(*prog)->sprites[empty] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/empty.xpm", &width, &width);
	(*prog)->sprites[collect] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/collect.xpm", &width, &width);
	(*prog)->sprites[ext] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/ext.xpm", &width, &width);
	(*prog)->sprites[player] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_action.xpm", &width, &width);
	(*prog)->sprites[p_jump] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/p_jump.xpm", &width, &width);
}

void	ft_init_player(t_prog **prog)
{
	int	width;

	width = 50;
	(*prog)->player.p_img[p_right] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_left.xpm", &width, &width);
	(*prog)->player.p_img[p_left] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_right.xpm", &width, &width);
	(*prog)->player.p_img[p_up] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_up.xpm", &width, &width);
	(*prog)->player.p_img[p_down] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_down.xpm", &width, &width);
	(*prog)->player.p_img[p_action] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/player_action.xpm", &width, &width);
}

int	map_int_valid(t_prog **prog)
{
	int	i;
	int	j;

	(*prog)->exit = 0;
	(*prog)->collectible = 0;
	(*prog)->start = 0;
	i = 0;
	j = -1;
	while (++j < (*prog)->height)
	{
		while (i < (*prog)->width)
		{
			if ((*prog)->map[j][i] == ext)
				(*prog)->exit++;
			if ((*prog)->map[j][i] == collect)
				(*prog)->collectible++;
			if ((*prog)->map[j][i] == player)
				(*prog)->start++;
			i++;
		}
		i = 0;
	}
	if ((*prog)->exit == 0 || (*prog)->collectible == 0 || (*prog)->start != 1)
		return (0);
	return (1);
}

int	valid_walls(t_prog **prog)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < (*prog)->height)
	{
		while (i < (*prog)->width)
		{
			if (j == 0 || j == ((*prog)->height - 1) || i == 0 \
						|| i == ((*prog)->width - 1))
			{
				if ((*prog)->map[j][i] != wall)
					return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
