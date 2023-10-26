/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:42:21 by riosorio          #+#    #+#             */
/*   Updated: 2023/04/07 13:39:07 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*solution;
	size_t	i;
	size_t	sz;

	i = 0;
	sz = ft_strlen(s);
	if (start > sz)
		len = 0;
	else if (len > (sz - start))
		len = sz - start;
	solution = malloc(sizeof(char) * (len + 1));
	if (!solution)
		return (NULL);
	while (start < sz && *(s + start + i) && len > i)
	{
		*(solution + i) = *(s + start + i);
		i++;
	}
	*(solution + i) = 0;
	return (solution);
}
