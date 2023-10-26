/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:57:32 by riosorio          #+#    #+#             */
/*   Updated: 2023/05/30 21:20:26 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, size_t len)
{
	int	sz;

	sz = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (len > 0)
	{
		if (write(1, (str + sz), 1) == -1)
			return (-1);
		len--;
		sz++;
	}
	return (sz);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}
