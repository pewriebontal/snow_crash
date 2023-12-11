/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:09:49 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/11 18:12:09 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../libft/ft_printf.h"
# include "../libft/gnl.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include "window.h"
# include <stdlib.h>

// GAME MAP CODES
# define PLAYER 'P'
# define EXIT 'E'
# define BITBERRY 'C'
# define WALL '1'
# define PATH '0'

// KEY CODES

// https://gist.github.com/Azeirah/9611830
// I dont know why it's hard to find keycodes
// but here it is
// ====================	Bon ====

# define ESC 53

# define W 119
# define A 97
# define S 115
# define D 100

# define A_UP 126
# define A_LEFT 65361
# define A_DOWN 125
# define A_RIGHT 65363

// ====================
# define SPRITE_SIZE 42

# define TRUE 1
# define FALSE 0

typedef struct s_sprite
{
	void		*player;

	void		*player_up;
	void		*player_right;
	void		*player_down;
	void		*player_left;

	void		*bit_berry;
	void		*exit_open;
	void		*exit_close;

	void		*wall;
	void		*path;

	int			width;
	int			height;
}				t_sprite;

typedef struct
{
	int			x;
	int			y;
	int			width;
	int			height;
}				rectangle;

typedef struct s_map
{
	int			map_col;
	int			map_row;
	char		**map;
}				t_map;

typedef struct s_game
{
	t_map		real_map;
	t_sprite	sprite;

}				t_game;

// INPUT
void			print_map(t_game *real_g);
void			load_asset(t_game *r_g_ptr, t_window *r_w_ptr);
void			paint(t_game *r_g_ptr, t_window *r_w_ptr);

void			paint_fr(t_window *r_w_ptr, void *img, int col, int row);
int				exit_program(t_window *window, t_game *game);

void			process_input(t_game *r_g_ptr, int keycode);
void			read_from_path(int fd, t_game *r_g_ptr);
int				read_keys(int keycode, t_window *r_w_ptr, t_game *r_g_ptr);
#endif // GAME_H
