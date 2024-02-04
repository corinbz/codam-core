NAME = pipex

# Flags
CFLAGS = -Wall -Wextra -Werror -g

# Src files
SRC = 

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -fr $(OBJ_DIR)

fclean: clean
	-rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
