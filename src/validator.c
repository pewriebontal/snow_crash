/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:59:35 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 10:50:07 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"

int	is_valid_map(t_game *g_ptr)
{
	return (1);
}

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
			&& (grid[newRow][newCol] == 'C' || grid[newRow][newCol] == '0' || grid[newRow][newCol] == 'E'))
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
