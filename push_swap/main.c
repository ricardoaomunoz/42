/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:18:02 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/18 14:19:30 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		one_param;

	lst_b = NULL;
	one_param = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			one_param = 1;
		}
		lst_a = ft_check_stack(argv, one_param);
		ft_find_max(&lst_a);
		ft_find_min(&lst_a);
		ft_sort(&lst_a, &lst_b);
		ft_lstclear(&lst_a, free);
		ft_lstclear(&lst_b, free);
		if (one_param)
			ft_clean_str(argv);
	}
	return (0);
}
