# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 14:08:49 by riosorio          #+#    #+#              #
#    Updated: 2023/12/12 18:26:28 by riosorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft

PRINT_DIR = lib/printf

UTIL_PATH = utilities

INCLUDE = -I. -I${LIBFT_DIR} -I${PRINT_DIR}

LIB = -L${LIBFT_DIR} -lft -L${PRINT_DIR} -lftprintf

LIBFT = libft.a

FTPRINTF = libftprintf.a

#UTILITIES = $(shell ls $(UTIL_PATH)/ft_*.c)
SOURCE = main.c utilities/ft_error.c utilities/ft_more_stack_utils.c utilities/ft_oper.c utilities/ft_sort.c utilities/ft_stack.c utilities/ft_stack_utils.c

all: dependencies ${NAME}

OBJECTS = $(SOURCE:%.c=%.o)

%.o: %.c
	$(CC) $(CC_FLAGS) $(INCLUDE) -O3 -o $@ -c $<

dependencies:
	@make bonus -C $(LIBFT_DIR)
	@make bonus -C $(PRINT_DIR)

${NAME}: ${OBJECTS}
	$(CC) $(OBJECTS) $(LIB) -o $@
	@echo "done name"

clean:
	@rm -rf $(OBJECTS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


