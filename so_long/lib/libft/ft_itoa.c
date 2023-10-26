/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 03:17:52 by rosorm            #+#    #+#             */
/*   Updated: 2023/10/25 20:41:57 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_int_sz(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	itoa_helper(char *str, int n, int len)
{
	str[len] = '\0';
	if (n == 0)
		*str = '0';
	else
	{
		if (n < 0)
		{
			*str = '-';
		}
		while (len-- > 0 && n != 0)
		{
			if (n < 0)
				str[len] = -(n % 10) + '0';
			else
				str[len] = (n % 10) + '0';
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		sz;

	sz = get_int_sz(n);
	ret = malloc(sizeof(char) * (sz + 1));
	if (!ret)
		return (NULL);
	if (ret)
		itoa_helper(ret, n, sz);
	return (ret);
}
