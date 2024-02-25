NAME = pipex

CFLAGS = -g

LIBFT = ./libft/libft.a
LIBFTDIR = ./libft/
OBJDIR = ./obj/

SRC = main.c\
	parse_input.c\
	pipex.c\
	error_handling.c\
	mem_free.c\
	file_handling.c\


#Colors

GREEN=\033[1;32m
BLUE=\033[1;36m
YELLOW=\033[1;33m
RED=\033[1;31m
NC=\033[0m # No Color

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))


$(OBJDIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GREEN)Compiled $< successfully!$(NC)"

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -I$(LIBFTDIR) -o $@
	@echo "$(BLUE)$(NAME) created successfully!$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@make -s -C $(LIBFTDIR) clean
	@echo "$(YELLOW)$(NAME) -> Object files removed!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFTDIR) fclean
	@echo "$(RED)$(NAME) executable removed!$(NC)"

re: fclean all

.PHONY: all clean fclean re
