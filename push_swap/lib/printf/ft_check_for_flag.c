/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:31:45 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/02 11:39:51 by rosorm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_variable(char c)
{
	if (c == 's' || c == 'd' || c == 'i' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'c' || c == 'u')
		return (1);
	return (0);
}

size_t	ft_check_error(char f, unsigned int flags, size_t length)
{
	if ((f == '+' || f == '#' || f == ' ') && ((flags & DOT_FLAG)
			|| (((flags & ZERO_FLAG) || (flags & MINUS_FLAG))
				&& length > 0)))
		return (1);
	else if (f == '0' && ((flags & DOT_FLAG) || (((flags & ZERO_FLAG)
					|| (flags & NUM_FLAG)) && length > 0)))
		return (1);
	else if (f == '-' && ((flags & DOT_FLAG) || (flags & NUM_FLAG)))
		return (1);
	else if (f > 48 && f < 58 && ((flags & DOT_FLAG) || (((flags & MINUS_FLAG)
					|| (flags & ZERO_FLAG)) && length > 0)))
		return (1);
	else if (f == '.' && ((flags & DOT_FLAG)))
		return (1);
	else if (ft_check_variable(f))
		return (0);
	else if (f == '0' || f == '+' || f == '#' || f == ' ' || f == '-'
		|| f == '.' || (f > 48 && f < 58))
		return (0);
	else
		return (2);
}

t_word_p	ft_print_flags(size_t f, char *c, int *l, va_list args)
{
	t_word_p	str;

	str = check_convertion(c, args);
	if (f & DOT_FLAG)
		ft_dot_flag(&str, *c, l[1]);
	if (f & PLUS_FLAG)
		ft_plus_flag(&str, *c);
	if (f & SPACE_FLAG)
		ft_space_flag(&str, *c);
	if (f & HASH_FLAG)
		ft_hash_flag(&str, *c);
	if ((f & ZERO_FLAG) && !(f & DOT_FLAG))
		ft_zero_flag(&str, *c, l[0]);
	if ((f & ZERO_FLAG) && (f & DOT_FLAG))
		ft_no_flag(&str, l[0]);
	if ((f & NUM_FLAG))
		ft_no_flag(&str, l[0]);
	if (f & MINUS_FLAG)
		ft_minus_flag(&str, l[0]);
	return (str);
}

void	ft_check_flags(char **c, int *width, size_t *i, size_t *flags)
{
	if (*(*c + *i) == '+')
		plus_flag(flags);
	else if (*(*c + *i) == ' ' && !(*flags & PLUS_FLAG))
		*flags = *flags | SPACE_FLAG;
	else if (*(*c + *i) == '#')
		*flags = *flags | HASH_FLAG;
	else if (*(*c + *i) == '-')
		*i += zero_minus_flag(flags, MINUS_FLAG, width, *c + *i + 1);
	else if (*(*c + *i) == '0')
		*i += zero_minus_flag(flags, ZERO_FLAG, width, *c + *i + 1);
	else if (*(*c + *i) == '.')
		dot_flag(flags, width, *c + *i + 1, i);
	else if ((*(*c + *i)) > 48 && (*(*c + *i)) < 58)
		num_flag(flags, width, *c, i);
	else
		*i -= 1;
}

t_word_p	check_for_flag(char **c, va_list args)
{
	size_t		flags;
	t_word_p	word;
	size_t		error;
	size_t		i;
	int			width[2];

	flags = 0;
	error = 0;
	width[0] = 0;
	width[1] = 0;
	i = 0;
	while (error == 0 && !ft_check_variable(*(*c + i)))
	{
		ft_check_flags(c, width, &i, &flags);
		i++;
		error = ft_check_error(*(*c + i), flags, width[0]);
	}
	*c = *c + i;
	word = (ft_print_flags(flags, *c, width, args));
	return (word);
}
