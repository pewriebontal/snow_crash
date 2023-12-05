/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:45 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/01 17:59:01 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

int	read_keys(int key_pressed, void *param)
{
	if (key_pressed == ESC)
		exit(EXIT_SUCCESS);
	else
		return (-1);
	return (0);
}