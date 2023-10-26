# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 12:19:44 by riosorio          #+#    #+#              #
#    Updated: 2023/10/25 10:35:00 by rosorm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SRCS :=  ${filter-out main ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

#BONUS := ${filter ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

SRCS := $(shell ls | grep -v ft_lst | grep ft_)

BONUS := $(shell ls | grep ft_lst)

NAME := libft.a

CFLAGS := -Wall -Werror -Wextra

AR := ar rc

OBJS := ${SRCS:.c=.o}

BONUS_OBJS := ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@${AR} $@ ${OBJS}
	@ranlib $@
	
bonus: ${OBJS} ${BONUS_OBJS}
	@${AR} ${NAME} ${OBJS} ${BONUS_OBJS}
	@ranlib ${NAME}

%.o: %.c
	@gcc ${CFLAGS} -c $< -o $@


clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f ${NAME}

re: fclean all

# Compile with a librarie generated =>  gcc main.c -L. (librarie is in current folder) -lstr
