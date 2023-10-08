# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdamian- < fdamian-@student.42malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 15:55:51 by fdamian-          #+#    #+#              #
#    Updated: 2023/10/08 14:50:34 by fdamian-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	  ft_calloc.c \
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
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_split.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c

BONUS_SRC =	ft_lstnew_bonus.c


BONUS_OBJ = $(BONUS_SRC:.c=.o)


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

bonus: $(BONUS_OBJ)
	@ar rc $(NAME) $(BONUS_OBJ)
	@echo "$(GREEN)Libft bonus compiled!$(DEF_COLOR)"

.PHONY: all, clean, fclean, re