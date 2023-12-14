/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:23 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 15:56:17 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../libft/gnl.h"

void	read_from_path(int fd, t_game *g_ptr)
{
	int		i;
	char	*buffer;

	i = 0;
	g_ptr->real_map.map = (char **)malloc(sizeof(char) * 750);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		g_ptr->real_map.map[i] = buffer;
		i++;
	}
}

void	print_map(t_game *g_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (g_ptr->real_map.map[row])
	{
		col = 0;
		while (g_ptr->real_map.map[row][col])
		{
			if (g_ptr->real_map.map[row][col] == WALL)
				ft_printf("1");
			if (g_ptr->real_map.map[row][col] == PATH)
				ft_printf("0");
			if (g_ptr->real_map.map[row][col] == PLAYER)
				ft_printf("P");
			if (g_ptr->real_map.map[row][col] == EXIT)
				ft_printf("E");
			if (g_ptr->real_map.map[row][col] == BITBERRY)
				ft_printf("C");
			col++;
		}
		ft_printf("\n");
		row++;
	}
}

void	locate_player(t_game *g_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (g_ptr->real_map.map[row])
	{
		col = 0;
		while (g_ptr->real_map.map[row][col])
		{
			if (g_ptr->real_map.map[row][col] == PLAYER)
			{
				g_ptr->player.row = row;
				g_ptr->player.col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

/*




int	ft_read_map(int fd, t_game *g_ptr)
{
		int             i;
		char    *buffer;

		g_ptr->real_map
				= ft_calloc(g_ptr->map_init.first_read_matrice + 1,
						sizeof(char *));
		if (!g_ptr->map_init.matrice)
		{
				ft_free_map(g_ptr);
				return (0);
		}
		i = 0;
		buffer = NULL;
		while (1)
		{
				buffer = get_next_line(fd);
				if (!buffer)
						break ;
				g_ptr->map_init.matrice[i] = buffer;
				i++;
		}
		if (!ft_check_read(g_ptr))
				return (0);
		return (1);
}*/