/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:58:09 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/19 14:58:47 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stacks(t_list **a, t_list **b, int des)
{
	int	size;
	int	position;
	int	forward;

	size = ft_lstsize(*b);
	position = 0;
	forward = 1;
	if (size > 1)
	{
		position = ft_get_position(*b, des, *a);
		if (position != 1)
		{
			if (position > size / 2)
			{
				forward = 0;
				position = size - position;
			}
			while (position-- && position != size)
				ft_move(b, forward);
		}
	}
	ft_push(a, b, des);
	if (position == 1)
		ft_swap(b, 0);
	ft_find_min(b);
}

void	ft_push_sort(t_list **a, t_list **b)
{
	t_stack	*head;
	int		size;

	ft_sort_stacks(a, b, 1);
	head = (t_stack *)((*b)->content);
	size = ft_lstsize(*b);
	if (head->min == '1' && size > 1)
		ft_rotate(b, 0);
}

void	ft_push_min(t_list **a, t_list **b)
{
	int	sizea;
	int	sizeb;
	int	eff;

	sizea = ft_lstsize(*a);
	sizeb = ft_lstsize(*b);
	if (sizeb > 2)
	{
		ft_calculate_effort(a, b, sizeb, sizea);
		eff = ft_find_min_eff(*a, ft_lstsize(*a));
		ft_sort_min(a, eff);
	}
	ft_sort_stacks(a, b, 1);
}

void	ft_sort_in_a(t_list **a, t_list **b)
{
	int		size;
	t_stack	*head;
	t_stack	*next;
	t_stack	*last;

	size = ft_lstsize(*b);
	if (!ft_is_sorted(*a, 0))
	{
		head = (t_stack *)((*a)->content);
		next = (t_stack *)((*a)->next->content);
		last = (t_stack *)(ft_lstlast(*a)->content);
		if (!((head->min == '1' && last->max == '1')
				|| (head->max == '1' && next->min == '1')
				|| (next->max == '1' && last->min == '1')))
			ft_swap(a, 0);
	}
	while (size > 0)
	{
		ft_sort_stacks(b, a, 0);
		size = ft_lstsize(*b);
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size > 3 && !ft_is_sorted(*a, 0))
	{
		ft_push_min(a, b);
		size = ft_lstsize(*a);
		ft_find_min(a);
	}
	ft_sort_in_a(a, b);
	ft_find_min(a);
	ft_organize(a);
}
