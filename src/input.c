/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:18 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 20:35:51 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int read_keys(int keycode, t_game *g_ptr)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		process_input(keycode, g_ptr);
	else if (keycode == A_UP || keycode == A_LEFT || keycode == A_DOWN || keycode == A_RIGHT)
		process_input(keycode, g_ptr);
	else if (keycode == ESC || keycode == Q)
	{
		g_ptr->go_code = GO_QUIT;
		game_over(g_ptr);
	}

	else if (keycode == SECRET_KEY)
	{
		g_ptr->is_use_cheat = TRUE;
		if (g_ptr->portal_open == FALSE)
			g_ptr->portal_open = TRUE;
		else
			g_ptr->portal_open = FALSE;
	}
	else
		return (-1);
	return (0);
}

void process_input(int keycode, t_game *g_ptr)
{
	if (keycode == W || keycode == A_UP)
	{
		g_ptr->player.direction = P_UP;
		process_movement(g_ptr, -1, 0);
	}
	else if (keycode == A || keycode == A_LEFT)
	{
		g_ptr->player.direction = P_LEFT;
		process_movement(g_ptr, 0, -1);
	}
	else if (keycode == S || keycode == A_DOWN)
	{
		g_ptr->player.direction = P_DOWN;
		process_movement(g_ptr, 1, 0);
	}
	else if (keycode == D || keycode == A_RIGHT)
	{
		g_ptr->player.direction = P_RIGHT;
		process_movement(g_ptr, 0, 1);
	}
}