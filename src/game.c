/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/05 09:06:41 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"

// Function to check if two rectangles collide
int	is_colliding(rectangle rect1, rectangle rect2)
{
	if (rect1.x + rect1.width >= rect2.x)
	{
		return (1);
	}
	else if (rect1.x <= rect2.x + rect2.width)
	{
		return (1);
	}
	else if (rect1.y + rect1.height >= rect2.y)
	{
		return (1);
	}
	else if (rect1.y <= rect2.y + rect2.height)
	{
		return (1);
	}
	else
		return (0); // Not colliding
}

int	update_game(void *param)
{
	// Your game logic goes here
	// Check for collision between player and an object
	//   if (isColliding(playerRect, objectRect)) {
	// Handle the collision (e.g., collect item, increase score)
	//   }
	return (0); // Returning 0 keeps the game loop running
}

int	main(int argc, char *argv[])
{
	t_window	real_g;

	real_g = new_program(300, 399, "Byte's Escape");
	if (!real_g.win_ptr || !real_g.mlx_ptr)
		return (1);
	//	mlx_key_hook (real_g.win_ptr, read_keys);
	mlx_loop_hook(real_g.mlx_ptr, update_game, NULL);
	mlx_loop(real_g.mlx_ptr);
	return (0);
}
