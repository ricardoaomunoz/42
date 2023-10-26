/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:22:08 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:53:52 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_img *img, t_point z, t_img sheet, int frame)
{
	int	o;
	int	os;

	o = (img->line_len * z.y) + (z.x * (img->bits_per_pixel / 8));
	os = (sheet.line_len * (z.y + (frame * PIX_Y)))
		+ (z.x * (sheet.bits_per_pixel / 8));
	*((unsigned int *)(o + img->addr)) = *((unsigned int *)(os + sheet.addr));
}

void	*ft_get_img(t_map *map, void *img, int frame)
{
	t_img	n_img;
	t_img	s_sheet;
	t_point	z;

	z.y = 0;
	s_sheet.img = img;
	s_sheet.addr = mlx_get_data_addr(s_sheet.img, &s_sheet.bits_per_pixel,
			&s_sheet.line_len, &s_sheet.endian);
	n_img.img = mlx_new_image(map->data.mlx_ptr, PIX_X, PIX_Y);
	n_img.addr = mlx_get_data_addr(n_img.img, &n_img.bits_per_pixel,
			&n_img.line_len, &n_img.endian);
	while (z.y < PIX_Y)
	{
		z.x = 0;
		while (z.x < PIX_X)
		{
			my_pixel_put(&n_img, z, s_sheet, frame);
			z.x++;
		}
		z.y++;
	}
	return (n_img.img);
}

void	save_frames(t_map *map, t_img_data *data, void *tile)
{
	int		f;
	void	**new;

	new = (void **)malloc(sizeof(void *) *(data->frames + 1));
	if (new == NULL)
		ft_error("malloc failed", map);
	f = 0;
	while (f < data->frames)
	{
		*(new + f) = ft_get_img(map, tile, f);
		f++;
	}
	*(new + f) = NULL;
	data->imgs = new;
}

void	set_images(t_map *map)
{
	map->images = malloc(sizeof(t_images));
	if (map->images == NULL)
		ft_error("malloc failed", map);
	map->images->wall.frames = 1;
	save_frames(map, &map->images->wall, map->tiles->wall);
	map->images->wall.img = map->images->wall.imgs[0];
	map->images->playerl.frames = 8;
	save_frames(map, &map->images->playerl, map->tiles->playerl);
	map->images->playerl.img = map->images->playerl.imgs[0];
	map->images->playerr.frames = 8;
	save_frames(map, &map->images->playerr, map->tiles->playerr);
	map->images->playerr.img = map->images->playerr.imgs[0];
	map->images->collect.frames = 2;
	save_frames(map, &map->images->collect, map->tiles->collect);
	map->images->collect.img = map->images->collect.imgs[0];
	map->images->exit.frames = 26;
	save_frames(map, &map->images->exit, map->tiles->exit);
	map->images->exit.img = map->images->exit.imgs[0];
	map->images->bg.frames = 1;
	save_frames(map, &map->images->bg, map->tiles->bg);
	map->images->bg.img = map->images->bg.imgs[0];
}

void	set_multimedia(t_map *map)
{
	map->tiles = malloc(sizeof(t_tiles));
	if (map->tiles == NULL)
		ft_error("malloc failed", map);
	map->tiles->wall = mlx_xpm_file_to_image(map->data.mlx_ptr,
			WALL_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->tiles->playerl = mlx_xpm_file_to_image(map->data.mlx_ptr,
			PLAYERL_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->tiles->playerr = mlx_xpm_file_to_image(map->data.mlx_ptr,
			PLAYERR_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->tiles->exit = mlx_xpm_file_to_image(map->data.mlx_ptr,
			EXIT_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->tiles->collect = mlx_xpm_file_to_image(map->data.mlx_ptr,
			COLLECT_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->tiles->bg = mlx_xpm_file_to_image(map->data.mlx_ptr,
			BG_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	set_images(map);
}
