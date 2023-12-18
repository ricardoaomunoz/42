/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:09:44 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/18 12:54:28 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_str(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

void	ft_error(t_list **lst, int one_param, char **argv)
{
	ft_printf("Error\n");
	if (lst)
		ft_lstclear(lst, free);
	if (one_param && argv)
	{
		ft_clean_str(argv);
	}
	exit(1);
}
