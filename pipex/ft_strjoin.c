/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:00:55 by riosorio          #+#    #+#             */
/*   Updated: 2023/09/06 15:46:51 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*solution;

	i = 0;
	lens1 = ft_strlen((char *) s1);
	lens2 = ft_strlen((char *) s2);
	solution = malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (!solution)
		return (NULL);
	while (*s1)
		*(solution + i++) = *s1++;
	while (*s2)
		*(solution + i++) = *s2++;
	*(solution + i) = '\0';
	return (solution);
}
