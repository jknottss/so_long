/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC_WIN 17
# include <stdlib.h>
# include "mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_player
{
	void	*p_img[5];
	int		x;
	int		y;
}	t_player;

typedef struct s_prog
{
	void		*mlx;
	void		*win;
	void		*sprites[11];
	int			width;
	int			height;
	int			**map;
	int			exit;
	int			collectible;
	int			start;
	int			count;
	int			winner;
	t_player	player;
}	t_prog;

enum e_sprites {
	collect,
	ext,
	empty,
	wall,
	player,
	enemy,
	enemy_act,
	p_dead,
	p_jump,
	collect_bonus,
	collect_bonus_2
};

enum e_player {
	p_left,
	p_right,
	p_up,
	p_down,
	p_action
};

int		ft_exit(t_prog **mlx);
void	ft_init_img(t_prog **prog);
void	map_width_and_height(t_prog **prog, char *path_to_map);
void	map_to_arr(t_prog **prog, char *path_to_map);
void	ft_error(void);
int		map_valid(t_prog **prog, char *line);
int		ft_free_arr(t_prog **prog);
int		mem_for_int_arr(t_prog **prog);
void	map_to_int_arr(t_prog **prog, char **char_arr_map);
void	free_char_arr(int height, char **char_arr);
int		map_int_valid(t_prog **prog);
int		valid_walls(t_prog **prog);
void	exit_with_err(t_prog **prog);
void	check_and_create_map(t_prog **prog, char *argv);
void	ft_init_player(t_prog **prog);
void	draw_floor(t_prog **prog);
void	draw_sprites(t_prog **prog, int sprite);
void	draw_map(t_prog **prog);
void	draw_player(t_prog **prog, int sprite);
int		key_handler(int keycode, t_prog **prog);
void	find_player(t_prog **prog);
void	set_sprite_and_draw(int keycode, t_prog **prog);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	init_enemy_char(t_prog **prog, char **char_arr_map);
void	en_sprite_init(t_prog **prog);
void	draw_enemy(t_prog **prog);
void	ft_dead(t_prog **prog);
void	draw_act_bears(t_prog **prog);
char	*ft_itoa(int n);
void	draw_counter(t_prog **prog);
void	draw_for_bonus(t_prog **prog, int sprite);
void	ft_win(t_prog **prog);
int		player_jump(t_prog **prog);
void	draw_empty(t_prog **prog);

#endif
