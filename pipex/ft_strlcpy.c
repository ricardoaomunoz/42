/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:31:42 by riosorio          #+#    #+#             */
/*   Updated: 2023/09/20 21:06:01 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (dstsize - 1 > 0 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
			dstsize--;
		}
		*(dst + i) = 0;
	}
	return (ft_strlen((char *) src));
}
