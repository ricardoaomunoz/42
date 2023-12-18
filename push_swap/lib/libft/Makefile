# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 12:19:44 by riosorio          #+#    #+#              #
#    Updated: 2023/12/10 18:41:49 by rosorm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS :=  ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c \
ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
ft_bzero.c  ft_itoa.c ft_lstmap.c ft_memset.c ft_strdup.c ft_strncmp.c\
ft_calloc.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c\
ft_isalnum.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c\
ft_isalpha.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c\
ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c

BONUS_FILES := ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c
NAME := libft.a

BONUS := bon 

CFLAGS := -Wall -Werror -Wextra

AR := ar rc

OBJS := ${SRCS:.c=.o}

BONUS_OBJS := ${BONUS_FILES:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${BONUS_OBJS}
	@echo "name rule"
	${AR} ${NAME} ${OBJS} ${BONUS_OBJS}
	@ranlib ${NAME}
	
bonus: all

%.o: %.c
	@echo "rule .c.o"
	gcc ${CFLAGS} -c $< -o $@ 

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all

# Compile with a librarie generated =>  gcc main.c -L. (librarie is in current folder) -lstr
