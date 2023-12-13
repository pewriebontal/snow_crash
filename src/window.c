/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:25:32 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/13 21:21:07 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include "../mlx_linux/mlx.h"

int	init_window(t_window *w_ptr)
{
	int	col;
	int	row;

	col = 5;
	row = 5;
	w_ptr->width = col * SPRITE_SIZE;
	w_ptr->height = row * SPRITE_SIZE;
}

t_game	new_program(int w, int h, char *window_title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_game){mlx_ptr, mlx_new_window(mlx_ptr, w, h, window_title), w,
		h});
}

int	exit_program(t_game *r_g_ptr)
{
	if (r_g_ptr)
	{
		mlx_destroy_window(r_g_ptr->mlx_ptr, r_g_ptr->win_ptr);
		mlx_destroy_display(r_g_ptr->mlx_ptr);
	}
	if (r_g_ptr)
		free(r_g_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
