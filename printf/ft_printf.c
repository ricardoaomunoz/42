/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:12:16 by riosorio          #+#    #+#             */
/*   Updated: 2023/05/30 19:45:06 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_after(char **c, va_list arg_ptr)
{
	t_word_p	word;
	int			aux;

	*c = *c + 1;
	word = check_for_flag(c, arg_ptr);
	if (ft_putstr(word.str, word.str_sz) == -1 || (word.str == NULL))
	{
		free(word.str);
		return (-1);
	}
	aux = word.str_sz;
	free(word.str);
	return (aux);
}

int	ft_printf(const char *s, ...)
{
	va_list		arg_ptr;
	int			sz;
	char		*c;
	int			aux;

	c = (char *)s;
	sz = 0;
	va_start(arg_ptr, s);
	while (*c)
	{
		if (*c == '%')
			aux = ft_print_after(&c, arg_ptr);
		else
			aux = ft_putchar(*c);
		if (aux == -1)
			return (-1);
		sz += aux;
		c++;
	}
	va_end(arg_ptr);
	return (sz);
}
