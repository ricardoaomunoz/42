/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:28:15 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/26 01:49:57 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keysym, t_map *map)
{
	if (keysym == K_ESC)
	{
		ft_clean_all_map(map);
		exit(1);
	}
	if (map->player_m == 0)
	{
		if (keysym == K_W || keysym == K_AR_U)
			ft_move_up(map);
		if (keysym == K_D || keysym == K_AR_R)
			ft_move_right(map);
		if (keysym == K_S || keysym == K_AR_D)
			ft_move_down(map);
		if (keysym == K_A || keysym == K_AR_L)
			ft_move_left(map);
	}
	return (0);
}

int	on_x_press(t_map *map)
{
	ft_clean_all_map(map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map		map;

	if (argc != 2)
		return (1);
	set_data(&map);
	ft_check_map(argv, &map);
	map.data.mlx_ptr = mlx_init();
	map.data.win_ptr = mlx_new_window(map.data.mlx_ptr, PIX_X * (map.size.x)
			+ FRAME, PIX_Y * (map.size.y) + FRAME, "So Long");
	set_multimedia(&map);
	printf("multimedia done\n");
	if (!map.data.mlx_ptr)
		return (-1);
	if (!map.data.win_ptr)
		return (-1);
	mlx_loop_hook(map.data.mlx_ptr, ft_frame_refresh, &(map));
	mlx_hook(map.data.win_ptr, 17, 0, on_x_press, &map);
	mlx_key_hook(map.data.win_ptr, handle_input, &(map));
	mlx_loop(map.data.mlx_ptr);
	ft_clean_all_map(&map);
	return (0);
}
