/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:51:31 by riosorio          #+#    #+#             */
/*   Updated: 2023/04/07 21:43:53 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	r;
	size_t	i;

	l = 0;
	i = ft_strlen((char *) src);
	r = ft_strlen(dst);
	if (dstsize > 0)
	{
		while ((dstsize - l) > (r + 1) && *(src + l))
		{
			*(dst + r + l) = *(src + l);
			l++;
		}
		*(dst + r + l) = '\0';
	}
	if (r >= dstsize)
		r = dstsize;
	return (i + r);
}
