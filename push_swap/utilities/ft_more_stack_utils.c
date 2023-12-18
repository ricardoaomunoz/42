/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:24 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/19 14:58:48 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_organize(t_list **a)
{
	t_stack	*head;
	t_stack	*tail;
	int		size;
	int		pos;

	head = (t_stack *)((*a)->content);
	tail = (t_stack *)(ft_lstlast(*a)->content);
	size = ft_lstsize(*a);
	pos = ft_get_min_pos(*a);
	while (head->min != '1' || tail->max != '1')
	{
		if (pos > (size / 2))
			ft_rev_rotate(a, 0);
		else
			ft_rotate(a, 0);
		head = (t_stack *)((*a)->content);
		tail = (t_stack *)(ft_lstlast(*a)->content);
	}
}

void	ft_move(t_list **b, int forward)
{
	if (forward)
		ft_rotate(b, 0);
	else
		ft_rev_rotate(b, 0);
}

void	ft_calculate_effort(t_list **a, t_list **b, int sizeb, int sizea)
{
	int		eff;
	int		pos;
	t_list	*head;

	head = *a;
	eff = 0;
	while (head)
	{
		pos = ft_get_position(*b, 1, head);
		if (pos > (sizeb / 2))
			pos = sizeb - pos;
		if (eff > (sizea / 2))
		{
			((t_stack *)(head->content))->effort = sizea - eff;
			((t_stack *)(head->content))->rev = 1;
		}
		else
		{
			((t_stack *)(head->content))->effort = eff;
			((t_stack *)(head->content))->rev = 0;
		}
		((t_stack *)(head->content))->position = pos;
		eff++;
		head = head->next;
	}
}

void	ft_sort_min(t_list **a, int eff)
{
	int	size;
	int	rev;

	rev = 0;
	size = ft_lstsize(*a);
	if (eff > (size / 2))
	{
		rev = 1;
		eff = size - eff;
	}
	while (eff)
	{
		if (rev)
			ft_rev_rotate(a, 0);
		else
			ft_rotate(a, 0);
		eff--;
	}
}

int	ft_find_min_eff(t_list *a, int sizea)
{
	int		eff;
	int		pos;
	t_stack	*node;
	int		rev;

	node = (t_stack *)(a->content);
	pos = node->position;
	eff = node->effort;
	rev = node->rev;
	while (a && a->next)
	{
		node = (t_stack *)(a->next->content);
		if (pos + eff == 0)
			return (0);
		if ((node->position + node->effort) < (pos + eff))
		{
			pos = node->position;
			eff = node->effort;
			rev = node->rev;
		}
		a = a->next;
	}
	if (rev)
		return (sizea - eff);
	return (eff);
}
