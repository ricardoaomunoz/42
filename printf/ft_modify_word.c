/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:03:31 by riosorio          #+#    #+#             */
/*   Updated: 2023/05/31 20:37:11 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	insert_beginning(t_word_p *str, char new, size_t new_len, int take)
{
	size_t		str_len;
	size_t		i;
	size_t		sign;
	char		*new_str;

	i = 0;
	sign = 0;
	str_len = str->str_sz;
	if ((*(str->str) == '+' || *(str->str) == '-' || *(str->str) == ' ')
		&& new == '0')
		sign = 1;
	else if (((str->str)[0] == '0' && ((str->str)[1] == 'x'
		|| (str->str)[1] == 'X')) && new == '0')
		sign = 2;
	if (!take)
		new_len += sign;
	str->str_sz += new_len;
	new_str = malloc(sizeof(char) *(str_len + new_len + 1));
	ft_memmove(new_str, str->str, str_len + 1);
	free(str->str);
	str->str = new_str;
	ft_memmove((str->str) + new_len + sign, str->str + sign, str_len
		- sign + 1);
	while (new_len-- > 0)
		(str->str)[i++ + sign] = new;
}

void	insert_end(t_word_p *str, char new, size_t new_len)
{
	size_t		i;
	size_t		aux;
	char		*new_str;

	i = 0;
	new_str = malloc(sizeof(char) * (str->str_sz + new_len + 1));
	ft_memmove(new_str, str->str, str->str_sz + 1);
	free(str->str);
	str->str = new_str;
	aux = str->str_sz + new_len;
	while (new_len > 0)
	{
		(str->str)[str->str_sz + i] = new;
		i++;
		new_len--;
	}
	str->str_sz = aux;
}

void	cut_string(char **str, size_t numChars)
{
	size_t	len;

	len = ft_strlen(*str);
	if (numChars >= len)
		return ;
	(*str)[numChars] = '\0';
}
