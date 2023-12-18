/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:14:06 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/03 19:14:07 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	num_flag(size_t *flags, int *length, char *c, size_t *i)
{
	(length)[0] = ft_atoi(c + *i);
	*i += to_move(c + *i);
	*i -= 1;
	if (!(*flags & MINUS_FLAG) && !(*flags & ZERO_FLAG))
		*flags = *flags | NUM_FLAG;
}

void	dot_flag(size_t *flags, int *pres, char *c, size_t *i)
{
	(pres)[1] = ft_atoi(c);
	*i += to_move(c);
	*flags = *flags | DOT_FLAG;
}

void	plus_flag(size_t *flags)
{
	*flags = *flags | PLUS_FLAG;
	if (*flags & SPACE_FLAG)
		*flags -= PLUS_FLAG;
}

size_t	zero_minus_flag(size_t *flags, size_t flag, int *length, char *c)
{
	(length)[0] = ft_atoi(c);
	if (*c == ' ')
		*flags = *flags | SPACE_FLAG;
	if (*c == '+')
		*flags = *flags | PLUS_FLAG;
	*flags = *flags | flag;
	return (to_move(c));
}
