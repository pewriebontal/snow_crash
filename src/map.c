/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:10:23 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 12:49:46 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../libft/gnl.h"

void	read_from_path(int fd, t_game *r_g_ptr)
{
	int		i;
	char	*buffer;

	i = 0;
	r_g_ptr->real_map.map = (char **)malloc(sizeof(char) * 750);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		r_g_ptr->real_map.map[i] = buffer;
		i++;
	}
}

void	print_map(t_game *r_g_ptr)
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
				ft_printf("1");
			if (r_g_ptr->real_map.map[row][col] == PATH)
				ft_printf("0");
			if (r_g_ptr->real_map.map[row][col] == PLAYER)
				ft_printf("P");
			if (r_g_ptr->real_map.map[row][col] == EXIT)
				ft_printf("E");
			if (r_g_ptr->real_map.map[row][col] == BITBERRY)
				ft_printf("C");
			col++;
		}
		ft_printf("\n");
		row++;
	}
}

/*




int	ft_read_map(int fd, t_game *r_g_ptr)
{
		int             i;
		char    *buffer;

		r_g_ptr->real_map
				= ft_calloc(r_g_ptr->map_init.first_read_matrice + 1,
						sizeof(char *));
		if (!r_g_ptr->map_init.matrice)
		{
				ft_free_map(r_g_ptr);
				return (0);
		}
		i = 0;
		buffer = NULL;
		while (1)
		{
				buffer = get_next_line(fd);
				if (!buffer)
						break ;
				r_g_ptr->map_init.matrice[i] = buffer;
				i++;
		}
		if (!ft_check_read(r_g_ptr))
				return (0);
		return (1);
}*/