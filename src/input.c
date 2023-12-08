/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:18 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 13:22:07 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	read_keys(int key_pressed, t_window *r_w_ptr)
{
	if (key_pressed == ESC)
		exit_program(r_w_ptr);
	else
		return (-1);
	return (0);
}
