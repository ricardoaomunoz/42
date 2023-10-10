/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:04:54 by rosorm            #+#    #+#             */
/*   Updated: 2023/09/08 21:53:59 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char) * ft_strlen((char *) s) + 1);
	if (!copy)
		return (NULL);
	while (*(s + i))
	{
		*(copy + i) = *(s + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}
