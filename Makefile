# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:27:07 by mkhaing           #+#    #+#              #
#    Updated: 2023/12/03 11:21:09 by mkhaing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR=src/
LIBMLX = ./mlx_linux

CC		= tcc
CFLAGS	= -Wall -Wextra -Werror -D LINUX -fsanitize=leak
LFLAGS  = -L$(LIBMLX) -lmlx -lbsd -lXext -lX11 -lm

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

all:		${NAME}

$(NAME):	${OBJS}
		$(CC) $(SRCS) $(LFLAGS) -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
