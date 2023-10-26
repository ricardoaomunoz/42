/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:29:52 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 10:43:13 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening File", map);
	map->size.y = get_height(file);
	map->map = (char **)malloc(sizeof(char *) * (map->size.y + 1));
	if (map->map == NULL)
		ft_error("malloc failed", map);
	line = get_next_line(fd);
	map->size.x = ft_strlen(line) - 1;
	while (line)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	free(line);
}

void	get_element(t_map *map, int i, int j)
{
	t_point	*new;
	t_list	*newcoll;

	if (map->map[i][j] == 'P')
	{
		if (!map->player.x && !map->player.y)
			map->player = (t_point){j, i};
		else
			ft_error("more than one player in map", map);
	}
	else if (map->map[i][j] == 'E')
	{
		if (!map->exit.x && !map->exit.y)
			map->exit = (t_point){j, i};
		else
			ft_error("more than one exit in map", map);
	}
	else if (map->map[i][j] == 'C')
	{
		new = malloc(sizeof(t_point));
		*new = (t_point){j, i};
		newcoll = ft_lstnew(new);
		ft_lstadd_front(&(map->collectors), newcoll);
	}
}

void	ft_get_positions(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->size.y)
	{
		j = 0;
		while (j < map->size.x)
		{
			c = map->map[i][j];
			if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1')
				ft_error("ivalid character in map", map);
			get_element(map, i, j);
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(char **area, t_point size, t_point begin)
{
	if (begin.x >= size.x || begin.y >= size.y || begin.x < 0
		|| begin.y < 0 || area[begin.y][begin.x] == 'F'
		|| area[begin.y][begin.x] == '1')
		return ;
	area[begin.y][begin.x] = 'F';
	ft_flood_fill(area, size, (t_point){begin.x + 1, begin.y});
	ft_flood_fill(area, size, (t_point){begin.x - 1, begin.y});
	ft_flood_fill(area, size, (t_point){begin.x, begin.y + 1});
	ft_flood_fill(area, size, (t_point){begin.x, begin.y - 1});
}

void	ft_check_map(char **argv, t_map *map)
{
	char	**tmp;

	tmp = ft_split(argv[1], '.');
	if (tmp != NULL)
	{
		if (ft_strncmp(tmp[1], "ber", 3) != 0)
		{
			clean_doubleptr(tmp);
			ft_error("invalid extension", map);
		}
		clean_doubleptr(tmp);
		ft_read_map(argv[1], map);
		ft_get_positions(map);
		ft_flood_fill(map->map, map->size, map->player);
		check_map_rules(map);
	}
	else
		ft_error("invalid file format", map);
}
