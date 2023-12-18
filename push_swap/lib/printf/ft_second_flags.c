/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:59:45 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/07 17:59:48 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_flag(t_word_p *str, char c)
{
	if (c == 'd' || c == 'i')
	{
		if (str->str[0] != '-')
		{
			insert_beginning((str), '+', 1, 0);
		}
	}
}

void	ft_space_flag(t_word_p *str, char c)
{
	if ((c == 'i' || c == 'd') && (str->str[0] != '+' && str->str[0] != '-'))
	{
		insert_beginning((str), ' ', 1, 0);
	}
}

void	ft_hash_flag(t_word_p *str, char c)
{
	if (c == 'x' && !ft_just_zero(str->str))
	{
		insert_beginning((str), 'x', 1, 1);
		insert_beginning((str), '0', 1, 1);
	}
	else if (c == 'X' && !ft_just_zero(str->str))
	{
		insert_beginning((str), 'X', 1, 1);
		insert_beginning((str), '0', 1, 1);
	}
}
