/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:59:35 by mikhaing          #+#    #+#             */
/*   Updated: 2026/03/11 21:46:35 by mikhaing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

int	is_valid_map(t_game *g_ptr)
{
	if (check_empty_line(&g_ptr->test_map) == FALSE)
		return (ft_printf("Error\nEmpty lines in map\n"), FALSE);
	if (is_rectangle(&g_ptr->test_map) == FALSE)
		return (ft_printf("Error\nMap is not in valid shape.\n"), FALSE);
	if (has_valid_chars(&g_ptr->test_map) == FALSE)
		return (ft_printf("Error\nMap has invalid characters.\n"), FALSE);
	if (have_required(g_ptr) == FALSE)
		return (ft_printf("Error\nMap is missing required items.\n"), FALSE);
	if (is_surrounded_by_wall(&g_ptr->test_map) == FALSE)
		return (ft_printf("Error\nMap is not surrounded by wall\n"), FALSE);
	if (can_reach_all(g_ptr, &g_ptr->test_map) == FALSE)
		return (ft_printf("Error\nItems is not reachable\n"), FALSE);
	return (TRUE);
}

void	init_moves(int moves[4][2])
{
	moves[0][0] = -1;
	moves[0][1] = 0;
	moves[1][0] = 1;
	moves[1][1] = 0;
	moves[2][0] = 0;
	moves[2][1] = -1;
	moves[3][0] = 0;
	moves[3][1] = 1;
}

void	validator_algo(t_map *m_ptr, int row, int col)
{
	int		new_row;
	int		new_col;
	int		i;
	int		moves[4][2];
	char	tile;

	init_moves(moves);
	m_ptr->map[row][col] = 'V';
	i = 0;
	while (i < 4)
	{
		new_row = row + moves[i][0];
		new_col = col + moves[i][1];
		if (new_row >= 0 && new_row < m_ptr->map_row && new_col >= 0
			&& new_col < m_ptr->map_col)
		{
			tile = m_ptr->map[new_row][new_col];
			if (tile == EXIT)
				m_ptr->map[new_row][new_col] = 'V';
			else if (tile == BITBERRY || tile == PATH)
				validator_algo(m_ptr, new_row, new_col);
		}
		i++;
	}
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

int	can_reach_all(t_game *g_ptr, t_map *m_ptr)
{
	int	row;
	int	col;

	validator_algo(m_ptr, g_ptr->player.row, g_ptr->player.col);
	row = 0;
	while (m_ptr->map[row])
	{
		col = 0;
		while (m_ptr->map[row][col] && m_ptr->map[row][col] != '\n')
		{
			if (m_ptr->map[row][col] == 'C' || m_ptr->map[row][col] == 'E')
			{
				return (FALSE);
			}
			col++;
		}
		row++;
	}
	return (TRUE);
}
