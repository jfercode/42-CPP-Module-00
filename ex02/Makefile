# Name
NAME = tests

# Compiler & flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Iinclude

# Source files
SRC = source/Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
