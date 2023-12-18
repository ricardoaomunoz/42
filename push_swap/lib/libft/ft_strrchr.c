/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 06:23:31 by rosorm            #+#    #+#             */
/*   Updated: 2023/04/02 12:34:05 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *) s);
	while (len >= 0)
	{
		if (*(s + len) == (char)c)
			return ((char *)(s + len));
		len--;
	}
	return (0);
}
