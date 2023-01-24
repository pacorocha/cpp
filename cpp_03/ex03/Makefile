CC		= c++
CFLAGS	= -g -Wall -Wextra -Werror -Wshadow -std=c++98
NAME 	= diamondtrap
SRC 	= main.cpp \
		  ClapTrap.cpp \
		  ScavTrap.cpp \
		  FragTrap.cpp \
		  DiamondTrap.cpp
OBJ		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR	= obj

$(NAME):	$(OBJ_DIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean:	clean
		rm -rf $(NAME)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

re:		fclean $(NAME)