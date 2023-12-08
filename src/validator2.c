#include "../include/game.h"
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 22

// Function to perform DFS to check if all coins can be collected
void	dfs(t_map map, int row, int col)
{
	int	moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	int newRow, newCol;
	// Mark the current cell as visited
	map.map[row][col] = 'V';
	// Define the possible moves (up, down, left, right)
	// Explore all possible moves
	for (int i = 0; i < 4; ++i)
	{
		newRow = row + moves[i][0];
		newCol = col + moves[i][1];
		// Check if the new cell is within bounds and is a coin
		if (newRow >= 0 && newRow < map.map_row && newCol >= 0
			&& newCol < map.map_col && (map.map[newRow][newCol] == 'C'
				|| map.map[newRow][newCol] == '0'))
		{
			dfs(map, newRow, newCol);
		}
	}
}

// Function to check if all coins can be collected
int	canCollectAllCoins(t_map map)
{
	int playerRow, playerCol;
	// Find the starting position of the player 'P'
	for (int i = 0; i < map.map_row; ++i)
	{
		for (int j = 0; j < map.map_col; ++j)
		{
			if (map.map[i][j] == 'P')
			{
				playerRow = i;
				playerCol = j;
				break ;
			}
		}
	}
	// Perform DFS to check if all coins can be collected
	dfs(map, playerRow, playerCol);
	// Check if all coins are visited
	for (int i = 0; i < map.map_row; ++i)
	{
		for (int j = 0; j < map.map_col; ++j)
		{
			if (map.map[i][j] == 'C')
				return (0); // Not all coins can be collected
		}
	}
	return (1); // All coins can be collected
}

int	main(void)
{
	t_map	game_map;
	char	initial_map[ROWS][COLS] = {"11111111111111111111111",
			"1C000000000000100000001", "1000000000000000000C001",
			"1101110000111100C000001", "1E000000001111000000001",
			"1111111100011100P000001", "10110000000001000000001",
			"10C00000000001000000001", "1111110000111100000C001",
			"10000000000C00000000001"};

	game_map.map_row = ROWS;
	game_map.map_col = COLS;
	// Allocate memory for the map
	game_map.map = (char **)malloc(game_map.map_row * sizeof(char *));
	for (int i = 0; i < game_map.map_row; ++i)
	{
		game_map.map[i] = (char *)malloc(game_map.map_col * sizeof(char));
	}
	// Initialize the map
	// Copy the initial_map to game_map.map
	for (int i = 0; i < game_map.map_row; ++i)
	{
		for (int j = 0; j < game_map.map_col; ++j)
		{
			game_map.map[i][j] = initial_map[i][j];
		}
	}
	if (canCollectAllCoins(game_map))
	{
		printf("The player can collect all coins.\n");
	}
	else
	{
		printf("The player cannot collect all coins.\n");
	}
	// Free allocated memory for the map
	for (int i = 0; i < game_map.map_row; ++i)
	{
		free(game_map.map[i]);
	}
	free(game_map.map);
	return (0);
}
