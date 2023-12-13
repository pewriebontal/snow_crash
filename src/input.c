/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:18 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/13 21:48:21 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	read_keys(int keycode, t_game *r_g_ptr)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		process_input(keycode, r_g_ptr);
	else if (keycode == A_UP || keycode == A_LEFT || keycode == A_DOWN
		|| keycode == A_RIGHT)
		process_input(keycode, r_g_ptr);
	else if (keycode == ESC)
		exit_program(r_g_ptr);
	else if (keycode == SECRET_KEY)
		if (r_g_ptr->portal_open == FALSE)
			r_g_ptr->portal_open = TRUE;
		else
			r_g_ptr->portal_open = FALSE;
	else
		return (-1);
	return (0);
}

void	process_input(int keycode, t_game *r_g_ptr)
{
	if (keycode == W || keycode == A_UP)
	{
		r_g_ptr->player_direction = P_UP;
		ft_printf("player direction: %d\n", r_g_ptr->player_direction);
		// Move player up
	}
	else if (keycode == A || keycode == A_LEFT)
	{
		r_g_ptr->player_direction = P_LEFT;
		// Move player left
	}
	else if (keycode == S || keycode == A_DOWN)
	{
		r_g_ptr->player_direction = P_DOWN;
		// Move player down
	}
	else if (keycode == D || keycode == A_RIGHT)
	{
		r_g_ptr->player_direction = P_RIGHT;
		// Move player right
	}
}