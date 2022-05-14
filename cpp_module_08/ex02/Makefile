CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror
CPP98		=	-std=c++98
RM			=	rm -f
NAME		=	a.out

SRC			=	main.cpp \
				mutantstack.cpp

OBJ			=	${SRC:.c=.o}

all			: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(CPP98) $(OBJ) -o $(NAME)

clean		:
	$(RM) *.o

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re