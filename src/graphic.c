/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:28:39 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 12:55:48 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

void	load_asset(t_game *r_g_ptr, t_window *r_w_ptr)
{
	int	width;
	int	height;

	r_g_ptr->sprite.player = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/player_default.xpm", &width, &height);
	r_g_ptr->sprite.player_up = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/player_up.xpm", &width, &height);
	r_g_ptr->sprite.player_right = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/player_right.xpm", &width, &height);
	r_g_ptr->sprite.player_down = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/player_down.xpm", &width, &height);
	r_g_ptr->sprite.player_left = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/player_left.xpm", &width, &height);
	r_g_ptr->sprite.wall = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/wall.xpm", &width, &height);
	r_g_ptr->sprite.path = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/path.xpm", &width, &height);
	r_g_ptr->sprite.exit_open = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/exit_open.xpm", &width, &height);
	r_g_ptr->sprite.exit_close = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/exit_close.xpm", &width, &height);
	r_g_ptr->sprite.bit_berry = mlx_xpm_file_to_image(r_w_ptr->mlx_ptr,
			"assets/xpm/bit_berry.xpm", &width, &height);
}

void	paint(t_game *r_g_ptr, t_window *r_w_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (r_g_ptr->real_map.map[row])
	{
		col = 0;
		while (r_g_ptr->real_map.map[row][col])
		{
			if (r_g_ptr->real_map.map[row][col] == WALL)
				paint_fr(r_w_ptr, r_g_ptr->sprite.wall, col, row);
			if (r_g_ptr->real_map.map[row][col] == PATH)
				paint_fr(r_w_ptr, r_g_ptr->sprite.path, col, row);
			if (r_g_ptr->real_map.map[row][col] == PLAYER)
				paint_fr(r_w_ptr, r_g_ptr->sprite.player, col, row);
			if (r_g_ptr->real_map.map[row][col] == EXIT)
				paint_fr(r_w_ptr, r_g_ptr->sprite.exit_close, col, row);
			if (r_g_ptr->real_map.map[row][col] == BITBERRY)
				paint_fr(r_w_ptr, r_g_ptr->sprite.bit_berry, col, row);
			col++;
		}
		row++;
	}
}

void	paint_fr(t_window *r_w_ptr, void *img, int col, int row)
{
	mlx_put_image_to_window(r_w_ptr->mlx_ptr, r_w_ptr->win_ptr, img, (col
			* SPRITE_SIZE), (row * SPRITE_SIZE));
}
