NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = \
		./src/ft_printf.c \
		./src/ft_utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs ${NAME} ${OBJS}

clean:
	-rm -fr $(OBJS)
fclean:
	-rm -fr $(NAME)
re: fclean clean
.PHONY: all clean fclean re