/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_convertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:37:43 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/03 21:22:55 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_word_p	check_convertion(const char *c, va_list args)
{
	if (*c == 'c')
		return (ft_check_other(va_arg(args, int)));
	else if (*c == 's')
		return (ft_check_string(va_arg(args, char *)));
	else if (*c == 'p')
		return (ft_check_ln(args, "0123456789abcdef"));
	else if (*c == 'd' || *c == 'i')
		return (ft_check_int(args));
	else if (*c == 'u')
		return (ft_check_un(args, "0123456789"));
	else if (*c == 'X')
		return (ft_check_un(args, "0123456789ABCDEF"));
	else if (*c == 'x')
		return (ft_check_un(args, "0123456789abcdef"));
	else
		return (ft_check_other(*c));
}
