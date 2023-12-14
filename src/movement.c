/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:52 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 21:01:24 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void open_portal(t_game *g_ptr)
{
	if (g_ptr->portal_open == FALSE)
	{
		if (g_ptr->count.berry == 0)
			g_ptr->portal_open = TRUE;
	}
}

void process_movement(t_game *g_ptr, int n_row, int n_col)
{
	int new_row;
	int new_col;

	new_row = g_ptr->player.row + n_row;
	new_col = g_ptr->player.col + n_col;
	if (g_ptr->real_map.map[new_row][new_col] == WALL)
		return;
	if (g_ptr->real_map.map[new_row][new_col] == PATH)
	{
		g_ptr->real_map.map[g_ptr->player.row][g_ptr->player.col] = PATH;
		g_ptr->real_map.map[new_row][new_col] = PLAYER;
		g_ptr->player.row = new_row;
		g_ptr->player.col = new_col;
		g_ptr->player.move_count++;
		if (g_ptr->player.move_count == 69 || g_ptr->player.move_count == 420)
			ft_printf("[NICE!] %d [Achievement Unlocked: Nice!]\n", g_ptr->player.move_count);
		else if (g_ptr->player.move_count == 42)
			ft_printf("[STEPS] %d [Achievement Unlocked: The Answer to Life, the Universe, and Everything]\n", g_ptr->player.move_count);
		else
			ft_printf("[STEPS] %d\n", g_ptr->player.move_count);
	}
	if (g_ptr->real_map.map[new_row][new_col] == BITBERRY)
	{
		g_ptr->real_map.map[g_ptr->player.row][g_ptr->player.col] = PATH;
		g_ptr->real_map.map[new_row][new_col] = PLAYER;
		g_ptr->player.row = new_row;
		g_ptr->player.col = new_col;
		g_ptr->count.berry--;
		g_ptr->player.move_count++;
		if (g_ptr->player.move_count == 69 || g_ptr->player.move_count == 420)
			ft_printf("[NICE!] %d [Achievement Unlocked: Nice!]\n", g_ptr->player.move_count);
		else if (g_ptr->player.move_count == 42)
			ft_printf("[STEPS] %d [Achievement Unlocked: The Answer to Life, the Universe, and Everything]\n", g_ptr->player.move_count);
		else
			ft_printf("[STEPS] %d\n", g_ptr->player.move_count);
	}
	if (g_ptr->real_map.map[new_row][new_col] == EXIT)
	{
		if (g_ptr->portal_open == TRUE)
		{
			g_ptr->player.move_count++;
			if (g_ptr->player.move_count == 69 || g_ptr->player.move_count == 420)
				ft_printf("[NICE!] %d [Achievement Unlocked: Nice!]\n", g_ptr->player.move_count);
			else if (g_ptr->player.move_count == 42)
				ft_printf("[STEPS] %d [Achievement Unlocked: The Answer to Life, the Universe, and Everything]\n", g_ptr->player.move_count);
			else
				ft_printf("[STEPS] %d\n", g_ptr->player.move_count);
			g_ptr->go_code = GO_WIN;
			game_over(g_ptr);
		}
		else
			return;
	}
}