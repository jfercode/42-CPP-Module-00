# Name
NAME = phoneBook

# Compiler & flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

# Source files
SRC = source/PhoneBook.cpp source/Contact.cpp main.cpp
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
