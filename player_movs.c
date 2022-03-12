/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_prog **prog)
{
	int		y;
	int		x;

	if (keycode == ESC)
		ft_exit(prog);
	if ((*prog)->height == 0)
		return (0);
	y = (*prog)->player.y;
	x = (*prog)->player.x;
	if (keycode == LEFT && ((*prog)->map[y][x - 1]) != wall)
		(*prog)->player.x--;
	if (keycode == UP && ((*prog)->map[y - 1][x]) != wall)
		(*prog)->player.y--;
	if (keycode == RIGHT && ((*prog)->map[y][x + 1]) != wall)
		(*prog)->player.x++;
	if (keycode == DOWN && ((*prog)->map[y + 1][x]) != wall)
		(*prog)->player.y++;
	if (x != (*prog)->player.x || y != (*prog)->player.y)
	{
		mlx_put_image_to_window((*prog)->mlx, (*prog)->win, \
				(*prog)->sprites[empty], x * 50, y * 50);
		set_sprite_and_draw(keycode, prog);
		draw_counter(prog);
	}
	return (0);
}

void	draw_counter(t_prog **prog)
{
	write(1, "Steps count = ", 14);
	ft_putnbr((*prog)->count);
	write(1, "\n", 1);
}

void	set_sprite_and_draw(int keycode, t_prog **prog)
{
	int	sprite;

	if (keycode == LEFT)
		sprite = p_left;
	if (keycode == UP)
		sprite = p_up;
	if (keycode == RIGHT)
		sprite = p_right;
	if (keycode == DOWN)
		sprite = p_down;
	(*prog)->count++;
	if ((*prog)->map[(*prog)->player.y][(*prog)->player.x] == collect)
	{
		(*prog)->map[(*prog)->player.y][(*prog)->player.x] = empty;
		(*prog)->collectible--;
	}
	if ((*prog)->map[(*prog)->player.y][(*prog)->player.x] == ext && \
	(*prog)->collectible == 0)
	{
		write(1, "You WIN!\n", 9);
		ft_exit(prog);
	}
	draw_for_bonus(prog, sprite);
}

void	draw_for_bonus(t_prog **prog, int sprite)
{
	draw_player(prog, sprite);
	draw_sprites(prog, ext);
	draw_sprites(prog, wall);
}
