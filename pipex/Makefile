# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 19:34:38 by riosorio          #+#    #+#              #
#    Updated: 2023/09/20 21:06:00 by riosorio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SRCS :=  ${filter-out main ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

#BONUS := ${filter ${wildcard ft_lst*.c}, ${wildcard ft_*.c}}

#SRCS := $(shell ls | grep -v ft_lst | grep ft_)
SRCS = ft_strncmp.c ft_split.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_strlcpy.c ft_split_by_quotes.c pipex_utils.c pipex.c
#BONUS := 

NAME := pipex

CFLAGS := -Wall -Werror -Wextra

AR := ar rc

OBJS := ${SRCS:.c=.o}

BONUS_OBJS := ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "name rule"
	gcc ${OBJS} -o $(NAME) 
	#${AR} $@ ${OBJS}
	#ranlib $@
	
bonus: all 
	#${BONUS_OBJS}
	#${AR} ${NAME} ${BONUS_OBJS}
	#ranlib ${NAME}

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
