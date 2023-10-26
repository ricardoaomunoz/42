/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:10:17 by riosorio          #+#    #+#             */
/*   Updated: 2023/04/07 18:59:48 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_qdelimeter(char const *s, char c)
{
	int	q;

	q = 0;
	if (*s != c && *s)
		q = 1;
	while (*s)
	{
		while (*s == c && *(s + 1) == c)
			s++;
		if (*s == c && *(s + 1))
			q++;
		s++;
	}
	if (*s != '\0' && *s != c)
		q++;
	return (q);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	if (!dest)
		return (NULL);
	while ((src[c] != '\0') && (c < n))
	{
		dest[c] = src[c];
		c++;
	}
	while (c <= n)
	{
		dest[c] = '\0';
		c++;
	}
	return (dest);
}

void	clean_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	*help_func(char **array, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (*(s + i))
	{
		while (*s == c && *(s + 1) == c)
			s += 1;
		if (*s == c && *(s + 1))
			s += 1;
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
		{
			array[j++] = ft_strncpy(malloc(sizeof(char) * (i + 2)), s, i + 1);
			if (!array[j - 1])
			{
				clean_all(array);
				return (NULL);
			}
			s += (i + 1);
			i = -1;
		}
		i++;
	}
	array[j] = NULL;
	return ("shit");
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*test;

	array = malloc(sizeof(s) * (ft_get_qdelimeter(s, c) + 1));
	if (!array)
		return (NULL);
	test = help_func(array, s, c, 0);
	if (!test)
		return (NULL);
	return (array);
}
