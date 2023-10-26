/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:37:16 by riosorio            #+#    #+#           */
/*   Updated: 2023/04/02 11:16:20 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	if (lst)
	{
		if (*lst)
		{
			pl = ft_lstlast(*lst);
			pl->next = new;
		}
		else
			*lst = new;
	}
}
