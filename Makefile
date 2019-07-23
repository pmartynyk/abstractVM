
NAME	= abstractVM

LIBS	= IOperand.hpp\
		Main.class.hpp

SRC		= main.cpp\
		Main.class.cpp

OBJ		= $(SRC:.cpp=.o)

FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $^ -o $(NAME)

./%.o: ./%.cpp
	clang++ $(FLAG) -c $< -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all