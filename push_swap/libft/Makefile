# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corin <corin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 21:27:13 by corin             #+#    #+#              #
#    Updated: 2024/02/08 22:59:51 by corin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
FLAGS = -Wall -Wextra -Werror
CC = cc
OBJDIR = ./obj/
SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_split.c \
	ft_strchr.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_striteri.c

#Colors

GREEN=\033[1;32m
BLUE=\033[1;36m
YELLOW=\033[1;33m
RED=\033[1;31m
NC=\033[0m # No Color

OBJS = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))

$(OBJDIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled $< successfully!$(NC)"

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $@ $(OBJS)
	@ranlib $@
	@echo "$(BLUE)$(NAME) created successfully!$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(YELLOW)$(NAME) -> object files removed!$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed!$(NC)"

re: fclean all

.PHONY: all, clean, fclean, re
