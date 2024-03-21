/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2024/03/22 04:37:00 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void	first_run(t_game *g_ptr, int fd)
{
	read_from_path(fd, &g_ptr->test_map);
	g_ptr->portal_open = FALSE;
	g_ptr->count.berry = 0;
	g_ptr->count.exit = 0;
	g_ptr->count.player = 0;
	g_ptr->count.wall = 0;
	g_ptr->count.path = 0;
	count_items(g_ptr, &g_ptr->test_map);
	get_map_size(&g_ptr->test_map);
	locate_player(g_ptr, &g_ptr->test_map);
	if (is_valid_map(g_ptr) == FALSE)
	{
		exit_program(g_ptr);
	}
}

void	start_game(t_game *g_ptr, int fd)
{
	g_ptr->portal_open = FALSE;
	g_ptr->count.berry = 0;
	g_ptr->count.exit = 0;
	g_ptr->count.player = 0;
	g_ptr->count.wall = 0;
	g_ptr->count.path = 0;
	read_from_path(fd, &g_ptr->real_map);
	load_asset(g_ptr);
	get_map_size(&g_ptr->real_map);
	locate_player(g_ptr, &g_ptr->real_map);
	g_ptr->player.direction = P_RIGHT;
	g_ptr->player.move_count = 0;
	g_ptr->is_use_cheat = FALSE;
	count_items(g_ptr, &g_ptr->real_map);
	ft_printf("[STEPS] %d\n", g_ptr->player.move_count);
}

int	update_game(t_game *g_ptr)
{
	paint(g_ptr);
	open_portal(g_ptr);
	return (0);
}

int	game_over(t_game *g_ptr)
{
	if (g_ptr->is_use_cheat == TRUE)
	{
		if (g_ptr->go_code == GO_WIN)
			ft_printf("%s%s\n", MESSAGE_WIN_CHEAT_1, MESSAGE_WIN_CHEAT_2);
		else if (g_ptr->go_code == GO_LOSE)
			ft_printf("%s\n", MESSAGE_LOSE_CHEAT);
		else if (g_ptr->go_code == GO_QUIT)
			ft_printf("%s%s\n", MESSAGE_QUIT_CHEAT_1, MESSAGE_QUIT_CHEAT_2);
		else
			ft_printf("%s\n", MESSAGE_SKILL_ISSUE);
		exit_program(g_ptr);
	}
	else if (g_ptr->is_use_cheat == FALSE)
	{
		if (g_ptr->go_code == GO_WIN)
			ft_printf("%s\n", MESSAGE_WIN);
		else if (g_ptr->go_code == GO_LOSE)
			ft_printf("%s\n", MESSAGE_LOSE);
		else if (g_ptr->go_code == GO_QUIT)
			ft_printf("%s\n", MESSAGE_SKILL_ISSUE);
		else
			ft_printf("%s\n", MESSAGE_SKILL_ISSUE);
		exit_program(g_ptr);
	}
	return (0);
}

void	print_ascii_art(void)
{
	ft_printf("%s\n", ASCII_ART);
}
