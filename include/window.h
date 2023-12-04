/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:10:29 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/03 11:22:53 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_window;

t_window	new_program(int w, int h, char *str);

#endif
