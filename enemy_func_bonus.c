/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	en_sprite_init(t_prog **prog)
{
	int	width;

	width = 50;
	(*prog)->sprites[enemy] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/enemy.xpm", &width, &width);
	(*prog)->sprites[enemy_act] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/enemy_act.xpm", &width, &width);
	(*prog)->sprites[p_dead] = mlx_xpm_file_to_image((*prog)->mlx, \
	"imgs/p_dead.xpm", &width, &width);
}

void	draw_enemy(t_prog **prog)
{
	int	x;
	int	y;
	int	counter;

	counter = (*prog)->collectible / 2;
	while (counter)
	{
		x = rand() % ((*prog)->width - 1) + 1;
		y = rand() % ((*prog)->height - 1) + 1;
		if ((*prog)->map[y][x] == empty)
		{
			(*prog)->map[y][x] = enemy;
			counter--;
		}
	}
	draw_sprites(prog, enemy);
}

void	ft_dead(t_prog **prog)
{
	int	x;
	int	y;

	y = (*prog)->player.y;
	x = (*prog)->player.x;
	draw_floor(prog);
	mlx_put_image_to_window((*prog)->mlx, \
	(*prog)->win, (*prog)->sprites[p_dead], (x + 1) * 50, y * 50);
	mlx_put_image_to_window((*prog)->mlx, \
	(*prog)->win, (*prog)->sprites[empty], x * 50, y * 50);
	mlx_put_image_to_window((*prog)->mlx, \
	(*prog)->win, (*prog)->sprites[enemy_act], x * 50, y * 50);
	mlx_string_put((*prog)->mlx, (*prog)->win, ((*prog)->width * 50) / 2, \
	((*prog)->height * 50) / 2, 000000, "YOU ARE DEAD...");
	(*prog)->start = 0;
}

void	ft_win(t_prog **prog)
{
	int	x;
	int	y;

	y = (*prog)->player.y;
	x = (*prog)->player.x;
	draw_floor(prog);
	mlx_put_image_to_window((*prog)->mlx, \
	(*prog)->win, (*prog)->sprites[empty], x * 50, y * 50);
	mlx_string_put((*prog)->mlx, (*prog)->win, ((*prog)->width * 50) / 2, \
	((*prog)->height * 40) / 2, 000000, "YOU WIN!");
	(*prog)->start = 0;
	(*prog)->winner = 1;
}

int	player_jump(t_prog **prog)
{
	static void	*sprite = 0;

	if ((*prog)->winner)
	{
		usleep(20000);
		draw_empty(prog);
		if (sprite == ((*prog)->sprites[player]) || sprite == 0)
			sprite = (*prog)->sprites[p_jump];
		else
			sprite = (*prog)->sprites[player];
		mlx_put_image_to_window((*prog)->mlx, \
		(*prog)->win, sprite, ((*prog)->width * 50) / 2, \
		((*prog)->height * 55) / 2);
		usleep(300000);
	}
	return (0);
}
