/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 07:09:49 by mkhaing           #+#    #+#             */
/*   Updated: 2023/12/05 09:07:22 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../libft/ft_printf.h"
# include "../libft/gnl.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdlib.h>

// KEYS

# define ESC 53
# define UP 126
# define DOWN 125

// GAME MAP CODES
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define PATH '0'

// GAME KEYWORDS
# define W 119
# define A 97
# define LEFT 65361
# define S 115
# define D 100
# define RIGHT 65363
# define RESTART 114

# define SPRITE_SIZE 42

# define TRUE 1
# define FALSE 0

typedef struct s_sprite
{
	void	*xpm_ptr;
	int		w;
	int		h;
}			t_sprite;

typedef struct
{
	int		x;
	int		y;
	int		width;
	int		height;
}			rectangle;

// INPUT

int			read_keys(int key_pressed, void *param);

#endif // GAME_H
