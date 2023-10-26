/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:50:51 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:40:28 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_doubleptr(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_collect(t_list *collect)
{
	t_point	*p;
	t_list	*tmp;

	while (collect)
	{
		p = collect->content;
		free(p);
		tmp = collect;
		collect = collect->next;
		free(tmp);
	}
	free(collect);
}

void	free_images(void *mlx_ptr, void **img)
{
	int	i;

	i = 0;
	while (img[i])
	{
		mlx_destroy_image(mlx_ptr, img[i]);
		i++;
	}
	free(img);
}

void	clean_images(void *mlx_ptr, t_images *images, t_tiles *tiles)
{
	free_images(mlx_ptr, images->wall.imgs);
	free_images(mlx_ptr, images->playerr.imgs);
	free_images(mlx_ptr, images->playerl.imgs);
	free_images(mlx_ptr, images->collect.imgs);
	free_images(mlx_ptr, images->exit.imgs);
	free_images(mlx_ptr, images->bg.imgs);
	mlx_destroy_image(mlx_ptr, tiles->wall);
	mlx_destroy_image(mlx_ptr, tiles->playerr);
	mlx_destroy_image(mlx_ptr, tiles->playerl);
	mlx_destroy_image(mlx_ptr, tiles->collect);
	mlx_destroy_image(mlx_ptr, tiles->exit);
	mlx_destroy_image(mlx_ptr, tiles->bg);
	free(tiles);
	free(images);
}

void	ft_clean_all_map(t_map *map)
{
	if (map->map)
		clean_doubleptr(map->map);
	if (map->collectors)
		clean_collect(map->collectors);
	if (map->images && map->tiles)
		clean_images(map->data.mlx_ptr, map->images, map->tiles);
	if (map->data.mlx_ptr)
	{
		mlx_destroy_window(map->data.mlx_ptr, map->data.win_ptr);
		free(map->data.mlx_ptr);
	}
}
