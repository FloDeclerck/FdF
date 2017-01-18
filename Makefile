# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 12:40:36 by fdeclerc          #+#    #+#              #
#    Updated: 2017/01/18 15:38:58 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCPATH = ./

INCPATH = -I

LIBPATH = -L

SRCFILES = fdf.c \
		   ft_read_file.c \

OBJFILES = $(SRC:.c=.o)

LIBFILES =

SRC = $(addprefix $(SRCPATH), $(SRCFILES))
OBJ = $(addprefix $(OBJPATH), $(OBJFILES))
LFLAGS = $(LIBPATH) $(LIBFILES)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LFLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit
	libft/libft.a get_next_line/get_next_line.c

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) $(INCPATH) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
