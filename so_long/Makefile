# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riosorio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 19:47:05 by riosorio          #+#    #+#              #
#    Updated: 2023/10/26 03:04:52 by rosorm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

UNAME = $(shell uname)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

MLX_DIR = lib/mlx/

LIBFT_DIR = lib/libft/

PRINT_DIR = lib/printf/

GNL_DIR = lib/gnl

MLX = $(MLX_DIR)libmlx.a

LIBFT = $(LIBFT_DIR)libft.a

FTPRINTF = $(PRINT_DIR)libftprintf.a

INCLUDE = -Iheaders -Iheaders/macos -Ilib -I${MLX_DIR} -I${LIBFT_DIR} -I${GNL_DIR} -I${PRINT_DIR}

INCLUDE_BONUS = -Iheaders/bonus -Iheaders/macos -Ilib -I${MLX_DIR} -I${LIBFT_DIR} -I${GNL_DIR} -I${PRINT_DIR}

ifeq ($(UNAME),Linux)
	MLX_DIR = mlx_linux/
	MLX = $(MLX_DIR)libmlx.a
	INCLUDE = -Iheaders -Iheaders/linux -I${LIBFT_DIR} -I${GNL_DIR} -I${PRINT_DIR} -I/usr/include -Ilib -Imlx_linux
	INCLUDE_BONUS = -Iheaders/bonus -Iheaders/linux -I${LIBFT_DIR} -I${GNL_DIR} -I${PRINT_DIR} -I/usr/include -Ilib -Imlx_linux
	#LBX = -Lmlx_linux -lmlx_Linux -L/usr/lib -L${LIBFT_DIR} -lft -L${PRINT_DIR} -lftprintf -Ilib -Imlx_linux -lXext -lX11 -lm -lz
	LBX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MESSAGE = Running on Linux
else
	#LBX = -L${MLX_DIR} -lmlx -L${LIBFT_DIR} -lft -L${PRINT_DIR} -lftprintf -framework OpenGL -framework AppKit
	LBX = -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
	MESSAGE = Running on macOS
endif

UTILITIES = utilities/ft_error.c utilities/ft_map.c utilities/ft_images.c utilities/ft_draw_map.c utilities/ft_frame_refresh.c utilities/ft_move.c utilities/ft_clean_map.c utilities/ft_map_utils.c utilities/ft_lst_utils.c

UTILITIES_BONUS = utilities/ft_error.c bonus/ft_map_bonus.c bonus/ft_images_bonus.c bonus/ft_draw_map.c bonus/ft_frame_refresh.c utilities/ft_move.c utilities/ft_clean_map.c utilities/ft_map_utils.c utilities/ft_lst_utils.c bonus/ft_enemy.c

SOURCE = main.c lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c $(UTILITIES)

SOURCE_BONUS = main.c lib/gnl/get_next_line.c lib/gnl/get_next_line_utils.c $(UTILITIES_BONUS)

OBJECTS = $(SOURCE:.c=.o)

OBJECTS_BONUS = $(SOURCE_BONUS:.c=.o)

all: dependencies ${NAME}

%.o: %.c
	gcc $(CC_FLAGS) $(INCLUDE_BONUS) -O3 -o $@ -c $<


dependencies:
	@make -C $(MLX_DIR)
	@make bonus -C $(LIBFT_DIR)
	@make bonus -C $(PRINT_DIR)

${NAME}: ${OBJECTS}
	@gcc $(OBJECTS) $(LBX) $(MLX) $(LIBFT) $(FTPRINTF) -o $(NAME)
	@echo "done name"

bonus: dependencies ${OBJECTS_BONUS} 
	@gcc $(OBJECTS_BONUS) $(LBX) $(MLX) $(LIBFT) $(FTPRINTF) -o $(NAME)
	@echo "bonus"

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OBJECT_BONUS)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus


