/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:18 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/11 18:11:18 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	read_keys(int keycode, t_window *r_w_ptr, t_game *r_g_ptr)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		process_input(r_g_ptr, keycode);
	else if (keycode == ESC)
		exit_program(r_w_ptr, r_g_ptr);
	else
		return (-1);
	return (0);
}

void	process_input(t_game *r_g_ptr, int keycode)
{
	if (keycode == W || keycode == A_UP)
	{
		// Move player up
	}
	else if (keycode == A || keycode == A_LEFT)
	{
		// Move player left
	}
	else if (keycode == S || keycode == A_DOWN)
	{
		// Move player down
	}
	else if (keycode == D || keycode == A_RIGHT)
	{
		// Move player right
	}
}