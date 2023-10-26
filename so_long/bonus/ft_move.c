/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:43 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:42:24 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_map *map, int y, int x)
{
	if (map->map[y][x] == 'F')
	{
		map->player.y = y;
		map->player.x = x;
		if (!map->winner)
			map->movements++;
	}
	if (is_collect(x, y, map->collectors))
		delete_collect(x, y, &(map->collectors));
	if (map->exit.y == y && map->exit.x == x)
	{
		if (ft_lstsize(map->collectors) == 0)
			map->winner = 1;
	}
}

void	ft_move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y - 1;
	ft_move(map, y, x);
}

void	ft_move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x + 1;
	y = map->player.y;
	map->player_o = 'r';
	map->player_mov = 1;
	if (map->map[y][x] == 'F')
		map->player_m = 1;
	ft_move(map, y, x);
}

void	ft_move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y + 1;
	ft_move(map, y, x);
}

void	ft_move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x - 1;
	y = map->player.y;
	map->player_o = 'l';
	map->player_mov = 1;
	if (map->map[y][x] == 'F')
		map->player_m = 1;
	ft_move(map, y, x);
}
