
NAME = push_swap

# Dirs
LIBFT = ./libft/libft.a

# Flags
CFLAGS = -Wall -Wextra 

# Src files
SRC = $(wildcard *.c)

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -fr $(OBJ_DIR)
	make clean -C ./libft

fclean: clean
	-rm -fr $(NAME)
	-rm -fr $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
