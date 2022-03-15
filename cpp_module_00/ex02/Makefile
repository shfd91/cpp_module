# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 16:55:00 by sanghole          #+#    #+#              #
#    Updated: 2022/03/07 15:17:50 by sanghole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror
CPP98	=	-std=c++98
DEBUG	=	-g
AR		=	ar rcs
RM		=	rm -f
ASAN	=	-g3 -fsanitize=address

NAME	=	megaphone

SRC		=	megaphone.cpp

OBJ		=	${SRC:.c=.o}

%.o 		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all			: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(DEBUG) $(CFLAGS) $(CPP98) $(OBJ) -o $(NAME)
# $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean		:
	$(RM) *.o

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re