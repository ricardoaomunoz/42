/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:45:13 by riosorio          #+#    #+#             */
/*   Updated: 2023/04/12 16:55:22 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	sz;

	i = 0;
	j = 0;
	k = 0;
	sz = ft_strlen(needle);
	if (!needle[j] || haystack == needle)
		return ((char *) haystack);
	while (haystack[i] && needle[j] && sz >= (j + 1) && len > 0)
	{ 
		if (haystack[i] == needle[j])
		{
			j++;
			i++;
			len--;
		}
		else
		{
			k++;
			j = 0;
			len = len + (i - k);
			i = k;
		}
	}
	if ((j + 1) > sz && len >= 0)
		return ((char *) haystack + (i - j));
	else
		return (0);
} */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
