
NAME	= abstractVM

LIBS	= IOperand.hpp\
		Main.class.hpp\
		Exceptions.class.hpp\
		Operand.class.hpp\
		Command.class.hpp\
		Factory.class.hpp

SRC		= main.cpp\
		Main.class.cpp\
		Exceptions.class.cpp\
		Command.class.cpp\
		Factory.class.cpp

OBJ		= $(SRC:.cpp=.o)

FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -std=c++11 $(FLAG) $(OBJ) -o $(NAME) 

./%.o: ./%.cpp $(LIBS)
	clang++ -std=c++11 $(FLAG) -c $< -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all