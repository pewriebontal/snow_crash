/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:59:35 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 11:29:36 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	is_valid_map(t_game *g_ptr)
{
	if (check_empty_line(&g_ptr->test_map) == FALSE)
		return (FALSE);
	else if (is_rectangle(&g_ptr->test_map) == FALSE)
		return (FALSE);
	else if (can_reach_all(&g_ptr->test_map) == FALSE)
		return (FALSE);
	else if (have_required(g_ptr) == FALSE)
		return (FALSE);
	else if (is_surrounded_by_wall(&g_ptr->test_map) == FALSE)
		return (FALSE);
	return (TRUE);
}

void	validator_algo(t_map *m_ptr, int row, int col)
{
}

int	is_surrounded_by_wall(t_map *m_ptr)
{
	int	row;
	int	col;

	row = 0;
	while (m_ptr->map[row])
	{
		col = 0;
		while (m_ptr->map[row][col] && m_ptr->map[row][col] != '\n')
		{
			if (row == 0 || row == m_ptr->map_row - 1)
			{
				if (m_ptr->map[row][col] != WALL)
					return (FALSE);
			}
			else if (col == 0 || col == m_ptr->map_col - 1)
			{
				if (m_ptr->map[row][col] != WALL)
					return (FALSE);
			}
			col++;
		}
		row++;
	}
	return (TRUE);
}

int	can_reach_all(t_map *m_ptr)
{
	return (TRUE);
}
