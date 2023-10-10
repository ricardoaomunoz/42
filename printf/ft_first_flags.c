/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:30:08 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/04 03:14:58 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dot_flag(t_word_p *str, char c, size_t pres)
{
	if (pres == 0 && ft_strncmp(str->str, "0", str->str_sz) == 0)
	{
		cut_string(&(str->str), pres);
		str->str_sz = ft_strlen(str->str);
	}
	else if (c == 's' && pres < str->str_sz)
	{
		cut_string(&(str->str), pres);
		str->str_sz = ft_strlen(str->str);
	}
	else if (c != 's' && pres >= str->str_sz)
	{
		insert_beginning((str), '0', pres - str->str_sz, 0);
	}
}

void	ft_zero_flag(t_word_p *str, char c, size_t lenght)
{
	int			sz;
	char		fill;

	if (c == 'c' || c == 's')
		fill = ' ';
	else
		fill = '0';
	sz = lenght - str->str_sz;
	if (sz > 0)
	{
		insert_beginning((str), fill, sz, 1);
	}
}

void	ft_no_flag(t_word_p *str, size_t lenght)
{
	int		sz;

	sz = lenght - str->str_sz;
	if (sz > 0)
	{
		insert_beginning((str), ' ', sz, 1);
	}
}

void	ft_minus_flag(t_word_p *str, size_t lenght)
{
	if (lenght > str->str_sz)
	{
		insert_end((str), ' ', lenght - str->str_sz);
	}
}	
