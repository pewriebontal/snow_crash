/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/03 11:37:51 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	main(int argc, char *argv[])
{
	t_window	real_g;

	real_g = new_program(300, 399, "Byte's Escape");
	if (!real_g.win_ptr || !real_g.mlx_ptr)
		return (1);
	mlx_key_hook (real_g.win_ptr, read_keys);
	mlx_loop(real_g.mlx_ptr);
	return (0);
}
