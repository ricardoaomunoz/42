/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:10:21 by riosorio          #+#    #+#             */
/*   Updated: 2023/10/25 21:32:07 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_just_zero(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char s)
{
	if (s == ' ' || s == '\t' || s == '\v'
		|| s == '\n' || s == '\r' || s == '\f')
		return (1);
	return (0);
}

size_t	to_move(char *s)
{
	size_t	i;

	i = 0;
	while (ft_isspace(*(s + i)))
		i += 1 ;
	if (*(s + i) == '+' || *(s + i) == '-')
		i += 1;
	while (ft_isdigit(*(s + i)))
		i += 1;
	return (i);
}

void	clean_all_p(char *str, int str_sz)
{
	ft_bzero(str, str_sz);
	free(str);
}
