
NAME	= abstractVM

SRC		= main.cpp\
		Main.class.cpp
		
FLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAG) $(SRC) $^ -o $(NAME)

./%.o: ./%.cpp
	clang++ $(FLAG) -c $< -o $@

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
