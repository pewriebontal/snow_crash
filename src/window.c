/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:25:32 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 01:52:28 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include "../mlx_linux/mlx.h"

int	init_window(t_window *w_ptr, t_map *m_ptr)
{
	w_ptr->width = m_ptr->map_col * SPRITE_SIZE;
	w_ptr->height = m_ptr->map_row * SPRITE_SIZE;
	return (0);
}

t_game	new_program(int w, int h, char *w_title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_game){mlx_ptr, mlx_new_window(mlx_ptr, w, h, w_title)});
}

int	exit_program(t_game *g_ptr)
{
	if (g_ptr)
	{
		free_all(g_ptr);
		mlx_destroy_window(g_ptr->mlx_ptr, g_ptr->win_ptr);
		mlx_destroy_display(g_ptr->mlx_ptr);
		if (g_ptr->mlx_ptr)
		{
			free(g_ptr->mlx_ptr);
			g_ptr->mlx_ptr = NULL;
		}
		g_ptr = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}
