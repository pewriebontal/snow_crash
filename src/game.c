/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 20:47:29 by mkhaing          ###   ########.fr       */
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
	g_ptr->count.berry = 1;
	g_ptr->portal_open = FALSE;
	g_ptr->player.direction = P_RIGHT;
	g_ptr->player.move_count = 0;
	g_ptr->is_use_cheat = FALSE;
	ft_printf("[STEPS] %d\n", g_ptr->player.move_count);
	if (is_valid_map(g_ptr) == FALSE)
		exit_program(g_ptr);
}

int update_game(t_game *g_ptr)
{
	open_portal(g_ptr);
	paint(g_ptr);
	return (0);
}

int game_over(t_game *g_ptr)
{
	if (g_ptr->is_use_cheat == TRUE)
	{
		if (g_ptr->go_code == GO_WIN)
			ft_printf("[Game Over] You Escaped using cheat, hope you're happy!\n");
		else if (g_ptr->go_code == GO_LOSE)
			ft_printf("[Game Over] You Cheated and still lose! LoL\n");
		else if (g_ptr->go_code == GO_QUIT)
			ft_printf("[Game Over] You Cheated and still quit? [BIG BIG] Skill Issue!\n");
		else
			ft_printf("[Game Over] Skill Issue!\n");
		exit_program(g_ptr);
	}
	else if (g_ptr->is_use_cheat == FALSE)
	{
		if (g_ptr->go_code == GO_WIN)
			ft_printf("[Game Over] You Escaped!\n");
		else if (g_ptr->go_code == GO_LOSE)
			ft_printf("[Game Over] You Died!\n");
		else if (g_ptr->go_code == GO_QUIT)
			ft_printf("[Game Over] Skill Issue!\n");
		else
			ft_printf("[Game Over] Skill Issue!\n");
		exit_program(g_ptr);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_game real_g;
	int fd;

	init_window(&real_g.window);
	real_g = new_program(real_g.window.width, real_g.window.height,
						 WINDOW_TITLE);
	if (!real_g.win_ptr || !real_g.mlx_ptr)
		return (1);
	fd = open(argv[1], O_RDONLY);
	start_game(&real_g, fd);
	mlx_hook(real_g.win_ptr, 17, 0, game_over, &real_g);
	mlx_key_hook(real_g.win_ptr, read_keys, &real_g);
	mlx_loop_hook(real_g.mlx_ptr, update_game, &real_g);
	mlx_loop(real_g.mlx_ptr);
	return (0);
}
