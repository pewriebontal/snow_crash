/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 17:02:40 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include <fcntl.h>


void start_game(t_game *g_ptr, int fd)
{
	read_from_path(fd, g_ptr);
	print_map(g_ptr);
	load_asset(g_ptr);
	locate_player(g_ptr);

	g_ptr->berry_count = 1;
	g_ptr->portal_open = FALSE;
	g_ptr->player.direction = P_RIGHT;


	if(is_valid_map(g_ptr) == FALSE)
		exit_program(g_ptr);
}

int	update_game(t_game *g_ptr)
{
	open_portal(g_ptr);
	paint(g_ptr);
	return (0); 
}


int game_over(t_game *g_ptr)
{
	
}


int	main(int argc, char *argv[])
{
	t_game	real_g;
	int		fd;

	init_window(&real_g.window);
	real_g = new_program(real_g.window.width, real_g.window.height,
			WINDOW_TITLE);
	if (!real_g.win_ptr || !real_g.mlx_ptr)
		return (1);
	fd = open(argv[1], O_RDONLY);

	start_game(&real_g, fd);

	mlx_hook(real_g.win_ptr, 17, 0, exit_program, &real_g);
	mlx_key_hook(real_g.win_ptr, read_keys, &real_g);
	mlx_loop_hook(real_g.mlx_ptr, update_game, &real_g);
	mlx_loop(real_g.mlx_ptr);
	return (0);
}
