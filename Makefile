# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:27:07 by mkhaing           #+#    #+#              #
#    Updated: 2023/12/20 02:21:02 by mkhaing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR=src/
LIBMLX = ./mlx_linux
LIBFT = ./libft

CC		=  gcc
#CFLAGS	= -Wall -Wextra -Werror -D LINUX -fsanitize=leak
CFLAGS = -D LINUX -fsanitize=leak -g
#LFLAGS  = -L$(LIBMLX) -lmlx -lbsd -lXext -lX11 -lm
LFLAGS = -L$(LIBMLX) -L$(LIBFT) -l:libft.a -lbsd -lmlx_Linux -lXext -lX11 -lm -lz

RM		= rm -f

SO_LONG_SRC=$(SRC_DIR)game.c \
	    $(SRC_DIR)map.c \
	    $(SRC_DIR)window.c \
	    $(SRC_DIR)input.c \
		$(SRC_DIR)graphic.c \
		$(SRC_DIR)movement.c \
		$(SRC_DIR)validator.c \
		$(SRC_DIR)validator2.c \
		$(SRC_DIR)free.c \
		$(SRC_DIR)main.c
			
	
SRCS	= $(SO_LONG_SRC)

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

all:		$(LIBFT) $(LIBMLX) $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBMLX):
		make -C $(LIBMLX) all

$(LIBFT):
		make -C $(LIBFT) all

%.o: %.c
			$(CC) $(CFLAGS) $(LFLAGS) $(LIBFT) -Imlx_linux -O3 -c $< -o $@

clean:
			${RM} ${OBJS}
			make -C $(LIBMLX) clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
