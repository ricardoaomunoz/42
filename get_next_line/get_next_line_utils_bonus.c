/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:31:39 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/28 17:46:10 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_mem(char **mem)
{
	int	i;

	i = 0;
	if (*mem)
	{
		while ((*mem)[i])
		{
			(*mem)[i] = '\0';
			i++;
		}
		free(*mem);
		*mem = NULL;
	}
}

size_t	check_end(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while ((str)[i] && (str)[i] != '\n')
		i++;
	if ((str)[i] == 0)
		return (0);
	return (i + 1);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	save_reminder(char **mem, size_t i, char **line)
{
	char	*aux;
	size_t	a;
	size_t	b;

	aux = malloc(sizeof(char) * (i + 2));
	b = 0;
	a = 0;
	while (a <= i)
	{
		aux[a] = (*line)[a];
		a++;
	}
	aux[a] = '\0';
	if (*mem)
		free(*mem);
	*mem = malloc(sizeof(char) * (ft_strlen(*line) - i + 1));
	while ((*line)[a])
	{
		(*mem)[b] = (*line)[a];
		a++;
		b++;
	}
	(*mem)[b] = '\0';
	free(*line);
	*line = aux;
}

void	join_new_line(char **new_line, char *mem)
{
	size_t	len_nl;
	size_t	len_mem;
	char	*aux;
	size_t	i;

	i = 0;
	len_nl = ft_strlen(*new_line);
	len_mem = ft_strlen(mem);
	aux = malloc(sizeof(char) * (len_mem + len_nl + 1));
	while ((*new_line) && (*new_line)[i])
	{
		aux[i] = (*new_line)[i];
		i++;
	}
	i = 0;
	while ((mem) && (mem)[i])
	{
		aux[i + len_nl] = (mem)[i];
		i++;
	}
	aux[i + len_nl] = '\0';
	clean_mem(new_line);
	*new_line = aux;
}
