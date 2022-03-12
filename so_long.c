/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:44:23 by                   #+#    #+#             */
/*   Updated: 2021/10/26 21:29:25 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_prog	*prog;

	(void) argc;
	prog = (t_prog *)malloc(sizeof (t_prog));
	if (!prog)
		return (0);
	prog->count = 0;
	check_and_create_map(&prog, argv[1]);
	prog->mlx = mlx_init();
	ft_init_img(&prog);
	ft_init_player(&prog);
	prog->win = mlx_new_window(prog->mlx, prog->width * 50, \
									prog->height * 50, "so_long");
	draw_map(&prog);
	find_player(&prog);
	draw_sprites(&prog, player);
	mlx_key_hook(prog->win, key_handler, &prog);
	mlx_hook(prog->win, ESC_WIN, 0, ft_exit, &prog);
	mlx_loop(prog->mlx);
	return (0);
}
