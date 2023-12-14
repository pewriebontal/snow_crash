/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:18 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 15:53:29 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	read_keys(int keycode, t_game *g_ptr)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		process_input(keycode, g_ptr);
	else if (keycode == A_UP || keycode == A_LEFT || keycode == A_DOWN
		|| keycode == A_RIGHT)
		process_input(keycode, g_ptr);
	else if (keycode == ESC)
		exit_program(g_ptr);
	else if (keycode == SECRET_KEY)
		if (g_ptr->portal_open == FALSE)
			g_ptr->portal_open = TRUE;
		else
			g_ptr->portal_open = FALSE;
	else
		return (-1);
	return (0);
}

void	process_input(int keycode, t_game *g_ptr)
{
	if (keycode == W || keycode == A_UP)
	{
		g_ptr->player.direction = P_UP;
		ft_printf("player moved up\n");
		process_movement(g_ptr, -1, 0);
		// Move player up
	}
	else if (keycode == A || keycode == A_LEFT)
	{
		g_ptr->player.direction = P_LEFT;
		ft_printf("player moved left\n");
		process_movement(g_ptr, 0, -1);
		// Move player left
	}
	else if (keycode == S || keycode == A_DOWN)
	{
		g_ptr->player.direction = P_DOWN;
		ft_printf("player moved down\n");
		process_movement(g_ptr, 1, 0);
		// Move player down
	}
	else if (keycode == D || keycode == A_RIGHT)
	{
		g_ptr->player.direction = P_RIGHT;
		ft_printf("player moved right\n");
		process_movement(g_ptr, 0, 1);
		// Move player right
	}
}