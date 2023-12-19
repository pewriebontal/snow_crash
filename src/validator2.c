/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:20:28 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 02:30:59 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	have_required(t_game *g_ptr)
{
	if (g_ptr->count.player != 1)
		return (FALSE);
	else if (g_ptr->count.exit != 1)
		return (FALSE);
	else if (g_ptr->count.berry == 0)
		return (FALSE);
	return (TRUE);
}

int	check_empty_line(t_map *m_ptr)
{
	int	i;

	if (m_ptr == NULL || m_ptr->map == NULL)
		return (FALSE);
	i = 0;
	while (m_ptr->map[i] != NULL)
	{
		if (ft_strlen(m_ptr->map[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_rectangle(t_map *m_ptr)
{
	int	first_row_length;
	int	i;

	if (m_ptr == NULL || m_ptr->map == NULL || m_ptr->map[0] == NULL)
		return (FALSE);
	ft_printf("passed 1\n");
	if (m_ptr->map_row <= 0 || m_ptr->map_col <= 0)
		return (FALSE);
	ft_printf("passed 2\n");
	first_row_length = ft_strlen(m_ptr->map[0]);
	ft_printf("first_row_length: %d\n", first_row_length);
	i = 1;
	while (i < m_ptr->map_row && ft_strlen(m_ptr->map[i]) == first_row_length)
		i++;
	ft_printf("i: %d\n", i);
	ft_printf("passed 3\n");
	if (i == m_ptr->map_row)
		return (TRUE);
	else
		return (FALSE);
}

void	count_items(t_game *g_ptr, t_map *m_ptr)
{
	int	row;
	int	col;

	if (g_ptr == NULL || m_ptr->map == NULL)
	{
		ft_printf("Error MAP count items\n");
		return ;
	}
	row = 0;
	while (m_ptr->map[row] != NULL)
	{
		col = 0;
		while (m_ptr->map[row][col] != '\0')
		{
			if (m_ptr->map[row][col] == PLAYER)
				g_ptr->count.player += 1;
			else if (m_ptr->map[row][col] == EXIT)
				g_ptr->count.exit += 1;
			else if (m_ptr->map[row][col] == BITBERRY)
				g_ptr->count.berry += 1;
			col++;
		}
		row++;
	}
}
