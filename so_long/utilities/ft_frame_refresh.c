/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_refresh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:12:53 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 22:05:19 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_refresh(t_map *map)
{
	t_images	*i;

	i = map->images;
	map->images->exit.img = map->images->exit.imgs[i->exit.frames];
	map->images->exit.frames++;
	map->frame = 0;
}

void	screen_refresh(t_map *map)
{
	t_images	*i;

	i = map->images;
	i->collect.img = map->images->collect.imgs[i->collect.frames];
	if (map->player_o == 'l')
		i->playerl.img = map->images->playerl.imgs[i->playerl.frames];
	else
		i->playerr.img = map->images->playerr.imgs[i->playerr.frames];
	map->images->collect.frames++;
	if (map->player_mov == 1 && map->player_o == 'r')
		map->images->playerr.frames++;
	if (map->player_mov == 1 && map->player_o == 'l')
		map->images->playerl.frames++;
	mlx_clear_window(map->data.mlx_ptr, map->data.win_ptr);
	ft_draw_map(map);
}

int	ft_frame_refresh(t_map *map)
{
	map->frame++;
	if (map->images->playerr.frames >= PLAYER_FRAMES
		|| map->images->playerl.frames >= PLAYER_FRAMES)
	{
		map->images->playerr.frames = 0;
		map->images->playerl.frames = 0;
		map->player_m = 0;
		map->player_mov = 0;
	}
	if (map->images->collect.frames >= COLLECT_FRAMES)
		map->images->collect.frames = 0;
	if (map->images->exit.frames >= EXIT_FRAMES
		|| (map->winner == 0 && map->images->exit.frames >= 5))
		map->images->exit.frames = 0;
	if (map->frame % 60 == 0)
		screen_refresh(map);
	if (map->frame % 120 == 0)
		exit_refresh(map);
	return (0);
}
