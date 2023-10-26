/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:33:43 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:28:38 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <get_next_line.h>
# include <libft.h>
# include <ft_printf.h>
# include <key.h>

# define PIX_X 96
# define PIX_Y 96
# define FRAME 90
# define WALL_PATH1 "./images/wall/BriBlock.xpm"
# define PLAYERL_PATH1 "./images/player/morty-left.xpm"
# define PLAYERR_PATH1 "./images/player/morty-right.xpm"
# define PLAYER_FRAMES 8
# define EXIT_PATH1 "./images/exit/portal2.xpm"
# define EXIT_FRAMES 26
# define COLLECT_PATH1 "./images/collectible/pickle1.xpm"
# define COLLECT_FRAMES 2
# define BG_PATH1 "./images/back-ground/Space_stars.xpm"

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_img_data {
	void	*img;
	int		frames;
	void	**imgs;
}	t_img_data;

typedef struct s_images {
	t_img_data	wall;
	t_img_data	playerr;
	t_img_data	playerl;
	t_img_data	collect;
	t_img_data	exit;
	t_img_data	bg;
}	t_images;

typedef struct s_tiles {
	void	*wall;
	void	*playerl;
	void	*playerr;
	void	*collect;
	void	*exit;
	void	*bg;
	int		height;
	int		width;
}	t_tiles;

typedef struct s_map {
	char		**map;
	char		player_o;
	int			player_m;
	int			player_mov;
	int			winner;
	int			movements;
	int			frame;
	t_point		size;
	t_point		player;
	t_point		exit;
	t_list		*collectors;
	t_images	*images;
	t_tiles		*tiles;
	t_mlx_data	data;
}	t_map;

void	ft_check_map(char **argv, t_map *map);
void	ft_error(char *msg, t_map *map);
void	set_data(t_map *map);
void	set_multimedia(t_map *map);
void	ft_draw_map(t_map *map);
int		ft_frame_refresh(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_right(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_left(t_map *map);
t_list	*is_collect(int x, int y, t_list *list);
void	delete_collect(int x, int y, t_list **list);
void	*ft_get_img(t_map *map, void *img, int frame);
void	ft_clean_all_map(t_map *map);
void	clean_doubleptr(char **map);
void	check_map_rules(t_map *maps);
int		get_height(char *file);

#endif
