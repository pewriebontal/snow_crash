/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:25:32 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 12:50:19 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include "../mlx_linux/mlx.h"

int	init_window(t_window *r_w_ptr)
{
	int	col;
	int	row;

	col = 6;
	row = 6;
	r_w_ptr->width = col * SPRITE_SIZE;
	r_w_ptr->height = row * SPRITE_SIZE;
}

t_window	new_program(int w, int h, char *window_title)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_window){mlx_ptr, mlx_new_window(mlx_ptr, w, h, window_title), w,
		h});
}

int	exit_program(t_window *r_w_ptr)
{
	if (r_w_ptr)
		mlx_destroy_window(r_w_ptr->mlx_ptr, r_w_ptr->win_ptr);
	exit(EXIT_SUCCESS);
}
