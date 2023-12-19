/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:59:35 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 02:29:42 by mkhaing          ###   ########.fr       */
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

void	validator_algo(t_game *g_ptr, int row, int col)
{
}

int	is_surrounded_by_wall(t_map *m_ptr)
{
	return (TRUE);
}

int	can_reach_all(t_map *m_ptr)
{
	return (TRUE);
}
