/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:40:52 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 16:09:54 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/game.h"

void	process_movement(t_game *g_ptr, int n_row, int n_col)
{
    int	new_row;
    int	new_col;

    new_row = g_ptr->player.row + n_row;
    new_col = g_ptr->player.col + n_col;
    if (g_ptr->real_map.map[new_row][new_col] == WALL)
        return ;
    if (g_ptr->real_map.map[new_row][new_col] == PATH)
    {
        g_ptr->real_map.map[g_ptr->player.row][g_ptr->player.col] = PATH;
        g_ptr->real_map.map[new_row][new_col] = PLAYER;
        g_ptr->player.row = new_row;
        g_ptr->player.col = new_col;
    }
    if (g_ptr->real_map.map[new_row][new_col] == BITBERRY)
    {
        g_ptr->real_map.map[g_ptr->player.row][g_ptr->player.col] = PATH;
        g_ptr->real_map.map[new_row][new_col] = PLAYER;
        g_ptr->player.row = new_row;
        g_ptr->player.col = new_col;
    }
    if (g_ptr->real_map.map[new_row][new_col] == EXIT)
    {
        if (g_ptr->portal_open == TRUE)
            exit_program(g_ptr);
        else
            return ;
    }

}
