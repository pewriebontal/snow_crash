/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:59:35 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/19 01:32:28 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	is_valid_map(t_game *g_ptr)
{
	if (check_empty_line(&g_ptr->test_map) == FALSE)
	{
		ft_printf("[Error] Empty line.\n");
		return (FALSE);
	}
	else if (is_rectangle(&g_ptr->test_map) == FALSE)
	{
		ft_printf("[Error] Not rectangle.\n");
		return (FALSE);
	}
	else if (can_reach_all(&g_ptr->test_map) == FALSE)
	{
		ft_printf("[Error] Cannot reach all.\n");
		return (FALSE);
	}
	else if (have_required(g_ptr) == FALSE)
	{
		ft_printf("[Error] Missing required item.\n");
		return (FALSE);
	}
	else if (is_surrounded_by_wall(&g_ptr->test_map) == FALSE)
	{
		ft_printf("[Error] Not surrounded by wall.\n");
		return (FALSE);
	}
	return (TRUE);
}

void	validator_main(t_game *g_ptr, int row, int col)
{
}

int	is_surrounded_by_wall(t_map *m_ptr)
{
	return (TRUE);
}

int	is_rectangle(t_map *m_ptr)
{
	int	first_row_length;
	int	i;

	if (m_ptr == NULL || m_ptr->map == NULL || m_ptr->map[0] == NULL)
	{
		return (FALSE);
	}
	ft_printf("passed 1\n");
	if (m_ptr->map_row <= 0 || m_ptr->map_col <= 0)
	{
		return (FALSE);
	}
	ft_printf("passed 2\n");
	first_row_length = ft_strlen(m_ptr->map[0]);
	ft_printf("first_row_length: %d\n", first_row_length);
	i = 1;
	while (i < m_ptr->map_row && ft_strlen(m_ptr->map[i]) == first_row_length)
	{
		i++;
	}
	ft_printf("i: %d\n", i);
	ft_printf("passed 3\n");
	if (i == m_ptr->map_row)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	check_empty_line(t_map *m_ptr)
{
	int	i;

	if (m_ptr == NULL || m_ptr->map == NULL)
	{
		return (FALSE);
	}
	i = 0;
	while (m_ptr->map[i] != NULL)
	{
		if (ft_strlen(m_ptr->map[i]) == 0)
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	can_reach_all(t_map *m_ptr)
{
	return (TRUE);
}

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
			{
				ft_printf("player++\n");
				g_ptr->count.player += 1;
			}
			else if (m_ptr->map[row][col] == EXIT)
			{
				ft_printf("exit++\n");
				g_ptr->count.exit += 1;
			}
			else if (m_ptr->map[row][col] == BITBERRY)
			{
				ft_printf("berry++\n");
				g_ptr->count.berry += 1;
			}
			col++;
		}
		row++;
	}
	ft_printf("player: %d\n", g_ptr->count.player);
	ft_printf("exit: %d\n", g_ptr->count.exit);
	ft_printf("berry: %d\n", g_ptr->count.berry);
}
/*
#include <stdio.h>

#define ROWS 10
#define COLS 22

// Function to perform DFS to check if all coins can be collected
void	dfs(char grid[ROWS][COLS], int row, int col)
{
	int	moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int	newRow;
	int	newCol;

	// Mark the current cell as visited
	grid[row][col] = 'V';
	// Define the possible moves (up, down, left, right)
	// Explore all possible moves
	for (int i = 0; i < 4; ++i)
	{
		newRow = row + moves[i][0];
		newCol = col + moves[i][1];
		// Check if the new cell is within bounds and is a coin
		if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS
			&& (grid[newRow][newCol] == 'C' || grid[newRow][newCol] == '0'
				|| grid[newRow][newCol] == 'E'))
		{
			dfs(grid, newRow, newCol);
		}
	}
}

// Function to check if all coins can be collected
int	canCollectAllCoins(char grid[ROWS][COLS])
{
	int playerRow, playerCol;
	// Find the starting position of the player 'P'
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			if (grid[i][j] == 'P')
			{
				playerRow = i;
				playerCol = j;
				break ;
			}
		}
	}
	// Perform DFS to check if all coins can be collected
	dfs(grid, playerRow, playerCol);
	// Check if all coins are visited
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			if (grid[i][j] == 'C' || grid[i][j] == 'E')
				return (0); // Not all coins can be collected
		}
	}
	return (1); // All coins can be collected
}

int	main(void)
{
	char	grid[ROWS][COLS] = {
			"11111111111111111111111",
			"1C000000000000100000001",
			"1000000000000000000C001",
			"1111110000111100C000001",
			"1E000000001111000000001",
			"1111111100011100P000001",
			"10110000000001000000001",
			"10C00000000001000000001",
			"1111110000111100000C001",
			"10000000000C00000000001"};
	if (canCollectAllCoins(grid))
	{
		printf("The player can collect all coins.\n");
	}
	else
	{
		printf("The player cannot collect all coins.\n");
	}
	return (0);
}
*/