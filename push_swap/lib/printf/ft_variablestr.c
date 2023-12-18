/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variablestr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:23:11 by riosorio          #+#    #+#             */
/*   Updated: 2023/05/31 20:42:20 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen(unsigned long int num, int base)
{
	int	result;

	result = 0;
	while (num / base >= 1)
	{
		result += 1;
		num = num / base;
	}
	result += 1;
	return (result);
}

char	*ft_get_lnb(unsigned long int num, char *base, char *str, int sz)
{
	int	base_sz;

	base_sz = ft_strlen(base);
	str[sz--] = '\0';
	if (num == 0)
	{
		str[sz] = base[num % base_sz];
		return (str);
	}
	while (num > 0)
	{
		str[sz] = base[num % base_sz];
		num /= base_sz;
		sz--;
	}
	return (str);
}
/*
int	main(void)
{
	int	n = 122;
	char *s;

	s = malloc(sizeof(char) * (2 + 1));
	s = ft_get_lnb(n, "0123456789ABCDEF", s, 2);
	printf("result %s \n", s);


	return (0);
}*/
