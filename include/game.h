/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:09:49 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/20 02:32:33 by mkhaing          ###   ########.fr       */
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
# define Q 113

# define GO_WIN 5555
# define GO_LOSE 6666
# define GO_QUIT 7777
# define GO_CHEAT 8888

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

# define MESSAGE_ACHIEV_42_1 "[Achievement Unlocked] The Answer to Life,"
# define MESSAGE_ACHIEV_42_2 " the Universe, and Everything!"
# define MESSAGE_ACHIEV_69 "[Achievement Unlocked] Nice!"

# define MESSAGE_WIN_CHEAT_1 "[Game Over] You Escaped using cheat,"
# define MESSAGE_WIN_CHEAT_2 " hope you're happy!"

# define MESSAGE_LOSE_CHEAT "[Game Over] You Cheated and still lose! LoLL"
# define MESSAGE_QUIT_CHEAT_1 "[Game Over] You Cheated and still quit?"
# define MESSAGE_QUIT_CHEAT_2 " [BIG BIG] Skill Issue!"
# define MESSAGE_SKILL_ISSUE "[Game Over] Skill Issue!"

# define MESSAGE_WIN "[Game Over] You Escaped!"
# define MESSAGE_LOSE "[Game Over] You Died!"

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

typedef struct s_count
{
	int			portal;
	int			berry;
	int			player;
	int			exit;
	int			wall;
	int			path;
	int			row;
	int			col;

}				t_count;

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
	int			move_count;

}				t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	window;

	t_count		count;
	t_map		real_map;
	t_map		test_map;
	t_sprite	sprite;
	t_player	player;

	int			is_use_cheat;
	int			portal_open;
	int			go_code;
}				t_game;

t_game			new_program(int w, int h, char *window_title);
int				init_window(t_window *r_w_ptr, t_map *m_ptr);
int				exit_program(t_game *game);

void			first_run(t_game *g_ptr, int fd);
void			start_game(t_game *g_ptr, int fd);
int				update_game(t_game *g_ptr);
int				game_over(t_game *g_ptr);

void			load_asset(t_game *g_ptr);
int				paint(t_game *g_ptr);
void			paint_fr(t_game *g_ptr, void *img, int col, int row);
void			paint_player(t_game *g_ptr, int col, int row);
void			paint_exit(t_game *g_ptr, int col, int row);

int				read_keys(int keycode, t_game *g_ptr);
void			process_input(int keycode, t_game *g_ptr);

void			read_from_path(int fd, t_map *m_ptr);
void			print_map(t_map *m_ptr);
void			locate_player(t_game *g_ptr);
void			get_map_size(t_map *m_ptr);

void			open_portal(t_game *g_ptr);
void			process_movement(t_game *g_ptr, int n_row, int n_col);
void			process_path(t_game *g_ptr, int new_row, int new_col);
void			process_exit(t_game *g_ptr, int new_row, int new_col);
void			process_bitberry(t_game *g_ptr, int new_row, int new_col);

int				is_valid_map(t_game *g_ptr);
void			validator_algo(t_game *g_ptr, int row, int col);
int				is_surrounded_by_wall(t_map *m_ptr);
int				can_reach_all(t_map *m_ptr);

int				have_required(t_game *g_ptr);
int				check_empty_line(t_map *m_ptr);
int				is_rectangle(t_map *m_ptr);
void			count_items(t_game *g_ptr, t_map *m_ptr);

void			free_all(t_game *g_ptr);
void			free_map(t_map *m_ptr);
void			free_graphic(t_game *g_ptr);

#endif // GAME_H
