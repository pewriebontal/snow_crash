/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:25:32 by mikhaing          #+#    #+#             */
/*   Updated: 2026/03/11 21:46:35 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include <game.h>
#include <window.h>

int	init_window(t_window *w_ptr, t_map *m_ptr)
{
	w_ptr->width = m_ptr->map_col * SPRITE_SIZE;
	w_ptr->height = m_ptr->map_row * SPRITE_SIZE;
	return (0);
}

int	exit_program(t_game *g_ptr)
{
	if (g_ptr)
	{
		free_all(g_ptr);
		if (g_ptr->mlx_ptr && g_ptr->win_ptr)
		{
			mlx_destroy_window(g_ptr->mlx_ptr, g_ptr->win_ptr);
			mlx_destroy_display(g_ptr->mlx_ptr);
		}
		if (g_ptr->mlx_ptr)
		{
			yeet(g_ptr->mlx_ptr);
			g_ptr->mlx_ptr = NULL;
		}
		g_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}
