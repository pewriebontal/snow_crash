/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:10:07 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 02:13:36 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/window.h"
#include <fcntl.h>

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		ft_printf("Map not found\n");
	}
	return (fd);
}

void	print_usage_error(void)
{
	ft_printf("Error\n");
	ft_printf("Usage: ./so_long [map.ber]\n");
}

void	initialize_game(t_game *real_g, int fd)
{
	first_run(real_g, fd);
	close(fd);
	init_window(&real_g->window, &real_g->test_map);
	*real_g = new_program(real_g->window.width, real_g->window.height,
			WINDOW_TITLE);
}

void	start_and_run_game(t_game *real_g, int fd)
{
	start_game(real_g, fd);
	close(fd);
	mlx_hook(real_g->win_ptr, 17, 0, game_over, real_g);
	mlx_key_hook(real_g->win_ptr, read_keys, real_g);
	mlx_loop_hook(real_g->mlx_ptr, update_game, real_g);
	mlx_loop(real_g->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_game	real_g;
	int		fd;

	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber",
			4) != 0)
	{
		print_usage_error();
		return (1);
	}
	fd = open_file(argv[1]);
	if (fd < 0)
		return (1);
	initialize_game(&real_g, fd);
	if (!real_g.win_ptr || !real_g.mlx_ptr)
		return (1);
	fd = open_file(argv[1]);
	start_and_run_game(&real_g, fd);
	return (0);
}
