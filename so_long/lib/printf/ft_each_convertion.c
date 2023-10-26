/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_each_convertion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:52:23 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/03 21:22:53 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_word_p	ft_check_un(va_list args, char *base)
{
	unsigned int	n;
	int				sz;
	t_word_p		str;

	n = va_arg(args, unsigned int);
	sz = numlen(n, ft_strlen(base));
	str.str = malloc(sizeof(char) * (sz + 1));
	if (str.str == NULL)
	{
		free(str.str);
		str.str = NULL;
		str.str_sz = 0;
	}
	else
	{
		str.str = ft_get_lnb(n, base, str.str, sz);
		str.str_sz = sz;
	}
	return (str);
}

t_word_p	ft_check_ln(va_list args, char *base)
{
	unsigned long int	n;
	int					sz;
	t_word_p			str;

	n = va_arg(args, unsigned long int);
	sz = numlen(n, ft_strlen(base));
	str.str = malloc(sizeof(char) * (sz + 3));
	if (str.str == NULL)
	{
		free(str.str);
		str.str = NULL;
		str.str_sz = 0;
	}
	else
	{
		str.str[0] = '0';
		str.str[1] = 'x';
		str.str = ft_get_lnb(n, base, str.str, sz + 2);
		str.str_sz = sz + 2;
	}
	return (str);
}

t_word_p	ft_check_int(va_list args)
{
	long int		n;
	int				sz;
	t_word_p		str;
	int				neg;

	sz = 0;
	neg = 0;
	n = va_arg(args, int);
	str.str_sz = 0;
	if (n < 0)
	{
		n *= -1;
		sz++;
		neg = 1;
	}
	sz += numlen(n, 10);
	str.str = malloc(sizeof(char) * (sz + 1));
	if (neg)
		str.str[0] = '-';
	str.str = ft_get_lnb(n, "0123456789", str.str, sz);
	str.str_sz += sz;
	return (str);
}

t_word_p	ft_check_other(int c)
{
	t_word_p	str;

	str.str = malloc(sizeof(char) + 2);
	if (str.str == NULL)
	{
		free(str.str);
		str.str = NULL;
		str.str_sz = 0;
	}
	else
	{
		str.str[0] = c;
		str.str[1] = '\0';
		str.str_sz = 1;
	}
	return (str);
}

t_word_p	ft_check_string(char *s)
{
	t_word_p	str;
	size_t		i;
	char		*aux;

	i = -1;
	if (s)
	{
		str.str = malloc(sizeof(char) * (ft_strlen(s) + 1));
		while (s[++i])
			str.str[i] = s[i];
		str.str[i] = '\0';
		str.str_sz = ft_strlen(str.str);
	}
	else
	{
		str.str = malloc(sizeof(char) * (6 + 1));
		str.str_sz = 6;
		aux = "(null)";
		while (aux[++i])
			str.str[i] = aux[i];
		str.str[i] = '\0';
	}
	return (str);
}
