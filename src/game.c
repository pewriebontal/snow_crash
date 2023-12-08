/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:04 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 13:14:39 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include <fcntl.h>

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
	t_window	real_w;
	t_game		real_g;
	int			fd;

	init_window(&real_w);
	real_w = new_program(real_w.width, real_w.height, WINDOW_TITLE);
	if (!real_w.win_ptr || !real_w.mlx_ptr)
		return (1);
	fd = open(argv[1], O_RDONLY);
	read_from_path(fd, &real_g);
	print_map(&real_g);
	load_asset(&real_g, &real_w);

	while(1)
	{
		paint(&real_g, &real_w);
		printf("painted\n");
	    usleep(16666);
	}


	
	//	mlx_key_hook (real_g.win_ptr, read_keys);
	//	mlx_loop_hook(real_g.mlx_ptr, update_game, NULL);
	mlx_loop(real_w.mlx_ptr);
	return (0);
}
