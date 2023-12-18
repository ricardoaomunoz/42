/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:46:44 by riosorio          #+#    #+#             */
/*   Updated: 2023/05/31 20:42:17 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unb(unsigned int nb, char *str, int sz)
{
	static int	len;

	len = 0;
	if (nb > 0)
	{
		ft_print_unb(nb / sz, str, sz);
		write(1, str + (nb % sz), 1);
		len += 1;
	}
	return (len);
}

int	ft_print_ulnb(unsigned long int nb, char *str, int sz)
{
	static int	len;

	len = 0;
	if (nb > 0)
	{
		ft_print_ulnb(nb / sz, str, sz);
		write(1, str + (nb % sz), 1);
		len += 1;
	}
	return (len);
}

int	ft_print_nb(int nb, char *str, int sz)
{
	static int	len;

	len = 0;
	if (nb > 0)
	{
		ft_print_nb(nb / sz, str, sz);
		write(1, str + (nb % sz), 1);
		len += 1;
	}
	if (nb < 0)
	{
		ft_print_nb(nb / sz, str, sz);
		write(1, str + -(nb % sz), 1);
		len += 1;
	}
	return (len);
}

int	ft_putnbr_base(void *nb, char *str, char c)
{
	int	sz;
	int	base_sz;

	sz = 0;
	base_sz = ft_strlen(str);
	if ((int)(intptr_t)nb < 0 && (c == 'i' || c == 'd'))
		sz += write(1, "-", 1);
	if ((int)(intptr_t)nb == 0 && (c != 'p'))
		sz += write(1, "0", 1);
	if (c == 'p')
	{
		sz += 2;
		if (!nb)
			sz += write(1, "0", 1);
		else
			sz += ft_print_ulnb((unsigned long int)nb, str, base_sz);
	}
	else if (c == 'u' || c == 'x' || c == 'X')
		sz += ft_print_unb((unsigned int)(intptr_t)nb, str, base_sz);
	else
		sz += ft_print_nb((int)(intptr_t)nb, str, base_sz);
	return (sz);
}
