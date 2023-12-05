# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:27:07 by mkhaing           #+#    #+#              #
#    Updated: 2023/12/05 08:28:44 by mkhaing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR=src/
LIBMLX = ./mlx_linux

CC		= gcc
#CFLAGS	= -Wall -Wextra -Werror -D LINUX -fsanitize=leak
CFLAGS = -D LINUX -fsanitize=leak
#LFLAGS  = -L$(LIBMLX) -lmlx -lbsd -lXext -lX11 -lm
LFLAGS = -L$(LIBMLX) -lbsd -lmlx_Linux -lXext -lX11 -lm -lz

RM		= rm -f

SO_LONG_SRC=$(SRC_DIR)game.c \
	    $(SRC_DIR)map.c \
	    $(SRC_DIR)event.c \
	    $(SRC_DIR)player.c \
	    $(SRC_DIR)window.c \
	    $(SRC_DIR)input.c
			
	
SRCS	= $(SO_LONG_SRC)

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

all:		 $(LIBMLX) $(NAME)

$(NAME):	 $(OBJS)
		$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBMLX):
		make -C $(LIBMLX) all

%.o: %.c
			$(CC) $(CFLAGS) $(LFLAGS) -Imlx_linux -O3 -c $< -o $@

clean:
			${RM} ${OBJS}
			make -C $(LIBMLX) clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
