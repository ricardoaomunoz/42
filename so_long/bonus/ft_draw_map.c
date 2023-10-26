/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:24 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/26 01:54:31 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collect(t_map *map, t_list *lst)
{
	int	x;
	int	y;

	while (lst)
	{
		x = ((t_point *)(lst->content))->x;
		y = ((t_point *)(lst->content))->y;
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->collect.img,
			(96 * x) + FRAME / 2, (96 * y) + FRAME / 2);
		lst = lst->next;
	}
}

void	draw_player(t_map *map)
{
	if (map->player_o == 'r' && map->winner == 0)
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->playerr.img, ((96 * map->player.x) + FRAME / 2)
			- ((map->player_m) * (96 - map->images->playerr.frames * 12)),
			(96 * map->player.y) + FRAME / 2);
	if (map->player_o == 'l' && map->winner == 0)
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->playerl.img, ((96 * map->player.x) + FRAME / 2)
			+ ((map->player_m) * (96 - map->images->playerl.frames * 12)),
			(96 * map->player.y) + FRAME / 2);
}

void	draw_element(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1')
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->wall.img, (96 * x) + FRAME / 2, (96 * y) + FRAME / 2);
	if (map->map[y][x] == 'F')
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->bg.img, (96 * x) + FRAME / 2, (96 * y) + FRAME / 2);
	if (x == map->exit.x && y == map->exit.y)
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->exit.img, (96 * x) + FRAME / 2, (96 * y) + FRAME / 2);
}

void	draw_steps(t_map *map)
{
	char	*tmp;

	if (map->winner)
	{
		mlx_string_put(map->data.mlx_ptr, map->data.win_ptr,
			5, 15, 0x00FFFFFF, "WINNER!!!!! number of steps: ");
		tmp = ft_itoa(map->movements);
		mlx_string_put(map->data.mlx_ptr, map->data.win_ptr,
			210, 15, 0x00FFFFFF, tmp);
		free(tmp);
	}
	else
	{
		mlx_string_put(map->data.mlx_ptr, map->data.win_ptr,
			5, 15, 0x00FFFFFF, "number of steps: ");
		tmp = ft_itoa(map->movements);
		mlx_string_put(map->data.mlx_ptr, map->data.win_ptr,
			120, 15, 0x00FFFFFF, tmp);
		free(tmp);
	}
}

void	ft_draw_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size.y)
	{
		x = 0;
		while (x < map->size.x)
		{
			draw_element(map, x, y);
			x++;
		}
		y++;
	}
	draw_player(map);
	draw_collect(map, map->collectors);
	draw_enemy(map, map->enemy);
	draw_steps(map);
}
