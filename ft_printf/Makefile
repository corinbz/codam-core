NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = \
		./src/ft_printf.c \
		./src/ft_put_hex.c \
		./src/ft_put_uns_nbr.c \
		./src/ft_putnbr.c \
		./src/ft_putstr.c \
		./src/ft_strlen.c \
		./src/ft_putadress.c \

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
