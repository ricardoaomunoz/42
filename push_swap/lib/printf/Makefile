# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 12:19:44 by riosorio          #+#    #+#              #
#    Updated: 2023/12/10 17:49:26 by rosorm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SRCS :=  ${filter-out main ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

#BONUS := ${filter ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

#SRCS := $(shell ls | grep -v ft_lst | grep ft_)
SRCS = ft_printf.c ft_check_for_flag.c ft_check_convertion.c ft_each_convertion.c ft_putstr.c ft_putnbr_base.c ft_variablestr.c ft_aux_func.c ft_first_flags.c ft_second_flags.c ft_modify_word.c ft_add_flags.c libft/ft_strncmp.c libft/ft_strlen.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_bzero.c libft/ft_memmove.c
#BONUS := 

NAME := libftprintf.a

CFLAGS := -Wall -Werror -Wextra

AR := ar rc

OBJS := ${SRCS:.c=.o}

BONUS_OBJS := ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "name rule"
	${AR} $@ ${OBJS}
	@ranlib $@
	
bonus: all 

%.o: %.c
	@echo "rule .c.o"
	gcc ${CFLAGS} -c $< -o $@


clean:
	/bin/rm -f *.o
	/bin/rm -f */*.o

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

# Compile with a librarie generated =>  gcc main.c -L. (librarie is in current folder) -lstr
