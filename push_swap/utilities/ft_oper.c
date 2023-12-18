/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:20:48 by riosorio          #+#    #+#             */
/*   Updated: 2023/12/19 14:58:48 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, int ss)
{
	t_list	*node2;
	t_list	*node1;
	t_stack	*num;

	node1 = *lst;
	num = (t_stack *)(node1->content);
	node2 = (*lst)->next;
	node1->next = node2->next;
	node2->next = node1;
	*lst = node2;
	if (!ss)
		ft_printf("s%c\n", num->stack);
}

void	ft_rotate(t_list **lst, int rr)
{
	t_list	*last_node;
	t_list	*node1;
	t_stack	*num;

	last_node = ft_lstlast(*lst);
	node1 = *lst;
	num = (t_stack *)(node1->content);
	*lst = node1->next;
	last_node->next = node1;
	node1->next = NULL;
	if (!rr)
		ft_printf("r%c\n", num->stack);
}

void	ft_rev_rotate(t_list **lst, int rrr)
{
	t_list	*last_node;
	t_list	*sec_last;
	t_stack	*num;

	last_node = *lst;
	num = (t_stack *)(last_node->content);
	sec_last = NULL;
	while (last_node->next != NULL)
	{
		sec_last = last_node;
		last_node = last_node->next;
	}
	last_node->next = *lst;
	sec_last->next = NULL;
	*lst = last_node;
	if (!rrr)
		ft_printf("rr%c\n", num->stack);
}

void	ft_push(t_list **lsta, t_list **lstb, int stack)
{
	t_list	*node;

	node = *lsta;
	*lsta = node->next;
	ft_lstadd_front(lstb, node);
	if (stack == 1)
	{
		((t_stack *)(node->content))->stack = 'b';
		ft_printf("pb\n");
	}
	else
	{
		((t_stack *)(node->content))->stack = 'a';
		ft_printf("pa\n");
	}
}
