NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRC = \

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs ${NAME} ${OBJS}

$(OBJ_DIR)%.o: ./src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -fr $(OBJ_DIR)
fclean: clean
	-rm -fr $(NAME)
re: fclean all
.PHONY: all clean fclean re
