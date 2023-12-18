/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:23:09 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/19 14:58:46 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_pos(t_list *a)
{
	int	pos;

	pos = 0;
	while (a && ((t_stack *)(a->content))->min != '1')
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

int	ft_get_position(t_list *lst, int des, t_list *first)
{
	int		position;
	t_stack	*head;
	t_stack	*next;
	t_stack	*node;

	node = (t_stack *)(first->content);
	next = ((t_stack *)(lst->content));
	head = (t_stack *)(ft_lstlast(lst)->content);
	position = 0;
	while ((lst) && ((des && !(node->num < head->num && node->num > next->num))
			|| (!des && !(node->num < next->num && node->num > head->num)))
		&& !((next->max == '1' && node->num > next->num)
			|| (next->min == '1' && node->num < next->num)))
	{
		position++;
		head = (t_stack *)(lst->content);
		if (lst->next)
			next = (t_stack *)(lst->next->content);
		lst = lst->next;
	}
	if ((des && (next->min == '1' && node->num < next->num))
		|| (!des & (next->max == '1' && node->num > next->num)))
		position++;
	return (position);
}

void	ft_find_max(t_list **lst)
{
	t_stack	*val;
	t_list	*head;
	int		max;

	if (*lst)
	{
		head = *lst;
		val = (t_stack *)head->content;
		max = val->num;
		val->max = '1';
		while (head)
		{
			if ((head->next) && ((t_stack *)(head->next->content))->num > max)
			{
				val->max = '0';
				val = (t_stack *)head->next->content;
				max = val->num;
				val->max = '1';
			}
			else if (head->next)
				((t_stack *)head->next->content)->max = '0';
			head = head->next;
		}
	}
}

void	ft_find_min(t_list **lst)
{
	t_stack	*val;
	t_list	*head;
	int		min;

	if (*lst)
	{
		head = *lst;
		val = (t_stack *)head->content;
		min = val->num;
		val->min = '1';
		while (head)
		{
			if ((head->next) && ((t_stack *)(head->next->content))->num < min)
			{
				val->min = '0';
				val = (t_stack *)head->next->content;
				min = val->num;
				val->min = '1';
			}
			else if (head->next)
				((t_stack *)head->next->content)->min = '0';
			head = head->next;
		}
	}
	ft_find_max(lst);
}

int	ft_is_sorted(t_list *lst, int des)
{
	t_stack	*node;
	t_stack	*next;

	while (lst && lst->next)
	{
		node = (t_stack *)((lst)->content);
		next = (t_stack *)((lst)->next->content);
		if (node->num < next->num && des
			&& (node->max != '1' || next->min != '1'))
			return (0);
		else if (node->num > next->num && !des
			&& (node->min != '1' || next->max != '1'))
			return (0);
		lst = lst->next;
	}
	return (1);
}
