#include "so_long.h"

void	add(t_map *map, int x, int y)
{
	t_point	*new;
	t_list	*newcoll;
	
	new = malloc(sizeof(t_point));
	*new = (t_point){x, y};
	newcoll = ft_lstnew(new);
	ft_lstadd_front(&(map->enemy), newcoll);

}
void	ft_add_enemy(t_map *map)
{
	int	x;
	int	y;
	char	c;

	x = rand() % (map->size.x - 1);
	y = rand() % map->size.y;
	c = map->map[y][x];
	printf("x: %d y: %d\n", map->size.x, map->size.y);
	printf("x: %d y: %d c: %c\n", x, y, c);
	while (c != 'F' || (x == map->player.x && y == map->player.y) || (x == map->exit.x && y == map->exit.y) || is_collect(x, y, map->collectors))
	{
		x = rand() % (map->size.x - 1);
		y = rand() % map->size.y;
		printf("x: %d y: %d c: %c\n", x, y, c);
		c = map->map[y][x];
	}
	add(map, x, y);
	
}

void	draw_enemy(t_map *map, t_list *lst)
{
	int	x;
	int	y;

	while (lst)
	{
		x = ((t_point *)(lst->content))->x;
		y = ((t_point *)(lst->content))->y;
	//	printf("draw enemy x: %d y: %d\n", x, y);
		mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
			map->images->enemy.img,
			(96 * x) + FRAME / 2, (96 * y) + FRAME / 2);
		lst = lst->next;
	}
}

void	set_enemy_multimedia(t_map *map)
{
	map->tiles->enemy = mlx_xpm_file_to_image(map->data.mlx_ptr,
			ENEMY_PATH1, &(map->tiles->width),
			&(map->tiles->height));
	map->images->enemy.frames = 4;
	save_frames(map, &map->images->enemy, map->tiles->enemy);
	map->images->enemy.img = map->images->enemy.imgs[0];
	map->enemy_r = 0;
}
