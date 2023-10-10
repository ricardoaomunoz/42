/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosorm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:52:28 by rosorm            #+#    #+#             */
/*   Updated: 2023/04/02 20:30:10 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *) dst;
	psrc = (const char *) src;
	if (pdst == NULL && psrc == NULL)
		return (NULL);
	while (n)
	{
		*(pdst++) = *(psrc++);
		n--;
	}
	return (dst);
}
