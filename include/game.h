/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:09:49 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/14 17:00:10 by mkhaing          ###   ########.fr       */
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

# define P_UP 1111
# define P_LEFT 2222
# define P_DOWN 3333
# define P_RIGHT 4444

// KEY CODES

// https://gist.github.com/Azeirah/9611830
// I dont know why it's hard to find keycodes
// but here it is
// ====================	Bon ====

# define ESC 65307

# define W 119
# define A 97
# define S 115
# define D 100

# define A_UP 65362
# define A_LEFT 65361
# define A_DOWN 65364
# define A_RIGHT 65363

# define SECRET_KEY 93 // ]
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

typedef struct s_rectangle
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_rectangle;

typedef struct s_map
{
	int			map_col;
	int			map_row;
	char		**map;
}				t_map;

typedef struct s_player
{
	int			col;
	int			row;
	int			direction;

}				t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	window;

	t_map		real_map;
	t_map		test_map;
	t_sprite	sprite;
	t_player	player;

	int			portal_open;
	int			berry_count;
}				t_game;

t_game			new_program(int w, int h, char *window_title);
int				exit_program(t_game *game);

void			read_from_path(int fd, t_game *g_ptr);
void			load_asset(t_game *g_ptr);
void 			locate_player(t_game *g_ptr);
int	is_valid_map(t_game *g_ptr);

void			print_map(t_game *g_ptr);

int				paint(t_game *g_ptr);
void			paint_fr(t_game *g_ptr, void *img, int col, int row);

void			process_input(int keycode, t_game *g_ptr);
int				read_keys(int keycode, t_game *g_ptr);

void			process_movement(t_game *g_ptr, int n_row, int n_col);
#endif // GAME_H
