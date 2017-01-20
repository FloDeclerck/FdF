# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 15:53:43 by fdeclerc          #+#    #+#              #
#    Updated: 2017/01/20 16:03:05 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_C = ./fdf.c \
		./read_line.c \
		./draw_map.c \
		./init_view.c \
		./controller.c

SRC_O = $(SRC_C:.c=.o)

SRC_H = fdf.h

SRC_A = libft/libft.a

FLAG = -Wall -Wextra -Werror

LIB = -L./libft -lft -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(SRC_O)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $^ $(LIB)

%.o: %.c
	gcc $(FLAG) -I libft/includes/ -c $<

clean:
	make -C libft/ clean
	rm -f $(SRC_O)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
