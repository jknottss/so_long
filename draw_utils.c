/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_prog **prog)
{
	draw_floor(prog);
	draw_sprites(prog, wall);
	draw_sprites(prog, collect);
	draw_sprites(prog, ext);
}

void	draw_floor(t_prog **prog)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	j = -1;
	x = 0;
	y = 0;
	while (++j < (*prog)->height)
	{
		while (++i <= (*prog)->width)
		{
			mlx_put_image_to_window((*prog)->mlx, (*prog)->win, \
			(*prog)->sprites[empty], x, y);
			x += 50;
		}
		i = 0;
		x = 0;
		y += 50;
	}
}

void	draw_sprites(t_prog **prog, int sprite)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (*prog)->height)
	{
		while (i < (*prog)->width)
		{
			if ((*prog)->map[j][i] == sprite)
			{
				mlx_put_image_to_window((*prog)->mlx, (*prog)->win, \
				(*prog)->sprites[sprite], i * 50, j * 50);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	find_player(t_prog **prog)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < (*prog)->height)
	{
		while (i < (*prog)->width)
		{
			if ((*prog)->map[j][i] == player)
			{
				(*prog)->player.x = i;
				(*prog)->player.y = j;
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_player(t_prog **prog, int p_sprite)
{
	int	y;
	int	x;

	y = (*prog)->player.y;
	x = (*prog)->player.x;
	mlx_put_image_to_window((*prog)->mlx, (*prog)->win, \
	(*prog)->player.p_img[p_sprite], x * 50, y * 50);
}
