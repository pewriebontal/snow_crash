/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 07:10:29 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/08 12:50:19 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# define WINDOW_TITLE "Byte's Escape, Yo!"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_window;

int			init_window(t_window *r_w_ptr);
t_window	new_program(int w, int h, char *str);
int			exit_program(t_window *window);

#endif
