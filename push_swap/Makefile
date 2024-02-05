
NAME = push_swap

# Dirs
LIBFT = ./libft/libft.a

# Flags
CFLAGS = -Wall -Wextra -Werror -g

# Src files
SRC = stack_operations.c \
      stack_utils.c \
	  check_input.c \
	  errors.c \
	  smaller_five.c \
	  radix_functions.c \
	  stack_intialization.c \
	  for_debugging.c \
	  main.c

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

$(LIBFT):
	make -C ./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
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
