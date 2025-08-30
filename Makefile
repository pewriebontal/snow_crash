# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:27:07 by mkhaing           #+#    #+#              #
#    Updated: 2024/03/22 04:41:58 by mkhaing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC_DIR	= src/
LIBFT_D =./byamc
MLX_D	= ./mlx_linux

LIBMLX	= $(MLX_D)/libmlx.a
LIBFT	= $(LIBFT_D)/byamc.a

CC	= cc

OPTI    = -march=native -funroll-loops -pipe -ffast-math
CFLAGS	= -I./include -I$(MLX_D) -I$(LIBFT_D)/include -Wall -Wextra -Werror -D LINUX $(OPTI) -std=gnu11  #-fsanitize=leak -g 
LFLAGS	= -lXext -lX11

RM	= rm -f

SO_LONG_SRC =	$(SRC_DIR)game.c \
		$(SRC_DIR)map.c \
		$(SRC_DIR)window.c \
		$(SRC_DIR)input.c \
		$(SRC_DIR)graphic.c \
		$(SRC_DIR)movement.c \
		$(SRC_DIR)validator.c \
		$(SRC_DIR)validator2.c \
		$(SRC_DIR)free.c \
		$(SRC_DIR)main.c
			
SRCS	    = 	$(SO_LONG_SRC)

OBJS	    =	${SRCS:.c=.o}

all:		$(LIBFT) $(LIBMLX) $(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(LIBMLX)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(LFLAGS) -o $(NAME)

$(LIBMLX):
		make -C $(MLX_D) all

$(LIBFT):
		make -C $(LIBFT_D) all

clean:
		${RM} ${OBJS}
		make -C $(MLX_D) clean
		make -C $(LIBFT_D) clean

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
