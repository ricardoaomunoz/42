/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                      +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 05:18:23 by rosorm            #+#    #+#             */
/*   Updated: 2023/04/02 11:16:03 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\n' || *nptr == '\r' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
