/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:22:36 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:43:45 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, int x, int y)
{
	int	j;
	int	sz;

	j = 0;
	while (map[j])
	{
		sz = ft_strlen(map[j]) - 1;
		if (sz != x)
			return (0);
		j++;
	}
	if (x == y)
		return (0);
	return (1);
}

int	is_sorrounded_by_walls(char **map, int i, int j)
{
	int	x;
	int	y;

	y = 0;
	while (y < j)
	{
		x = 0;
		while (x < i)
		{
			if ((x == 0 || x == i - 1) && map[y][x] != '1')
				return (0);
			if ((y == 0 || y == j - 1) && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_valid_path(char **map, t_point exit, t_point player, t_list *coll)
{
	t_point	*p;

	if (map[exit.y][exit.x] != 'F')
		return (0);
	if (map[player.y][player.x] != 'F')
		return (0);
	while (coll)
	{
		p = coll->content;
		if (map[p->y][p->x] != 'F')
			return (0);
		coll = coll->next;
	}
	return (1);
}

void	check_map_rules(t_map *maps)
{
	char	**map;
	int		x;
	int		y;

	map = maps->map;
	x = maps->size.x;
	y = maps->size.y;
	if (!is_rectangular(map, x, y))
		ft_error("map is not rectangular", maps);
	if (!is_sorrounded_by_walls(map, x, y))
		ft_error("map is not surronunded by walls", maps);
	if (!is_valid_path(map, maps->exit, maps->player, maps->collectors))
		ft_error("not valid path in map", maps);
	if (!maps->player.x && !maps->player.y)
		ft_error("no player in map", maps);
	if (!maps->exit.x && !maps->exit.y)
		ft_error("no exit in map", maps);
	if (ft_lstsize(maps->collectors) == 0)
		ft_error("no collectibles in map", maps);
}
