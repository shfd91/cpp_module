# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 16:55:00 by sanghole          #+#    #+#              #
#    Updated: 2022/05/02 10:33:30 by sanghole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
CPP98	=	-std=c++98
DEBUG	=	-g
AR		=	ar rcs
RM		=	rm -f
ASAN	=	-g3 -fsanitize=address

NAME	=	a.out

SRC		=	main.cpp

OBJ		=	${SRC:.c=.o}

%.o 		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all			: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(CPP98) $(OBJ) -o $(NAME)

clean		:
	$(RM) *.o

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re