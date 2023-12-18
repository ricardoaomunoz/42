/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:35:50 by riosorio          #+#    #+#             */
/*   Updated: 2023/04/02 21:52:36 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(unsigned char *) s1 == *(unsigned char *) s2 && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
