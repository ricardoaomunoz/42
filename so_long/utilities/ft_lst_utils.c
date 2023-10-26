/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:09:16 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:41:24 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*is_collect(int x, int y, t_list *list)
{
	t_point	*z;

	while (list)
	{
		z = (t_point *)list->content;
		if (z->x == x && z->y == y)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void	delete_collect(int x, int y, t_list **head)
{
	t_point	*z;
	t_list	*prev;
	t_list	*list;

	prev = NULL;
	list = *head;
	while (list)
	{
		z = (t_point *)list->content;
		if (z->x == x && z->y == y)
		{
			if (prev)
				prev->next = list->next;
			else
				*head = list->next;
			free(list->content);
			free(list);
			return ;
		}
		prev = list;
		list = list->next;
	}
}

int	get_height(char *file)
{
	int		h;
	int		fd;
	char	*line;

	h = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening File", NULL);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		h++;
	}
	free(line);
	return (h);
}

void	set_data(t_map *map)
{
	map->map = NULL;
	map->collectors = NULL;
	map->images = NULL;
	map->tiles = NULL;
	map->data.mlx_ptr = NULL;
	map->data.win_ptr = NULL;
	map->frame = 0;
	map->player_o = 'r';
	map->player_m = 0;
	map->player_mov = 0;
	map->winner = 0;
	map->movements = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
}
