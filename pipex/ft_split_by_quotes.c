/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:15:16 by riosorio          #+#    #+#             */
/*   Updated: 2023/09/23 17:20:00 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_size(char **commands)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (commands[i])
	{
		if (commands[i][0] == '\'')
		{
			size = ft_strlen(commands[i]);
			while (commands[i] && commands[i][size - 1] != '\'')
			{
				i++;
				size = ft_strlen(commands[i]);
			}
		}
		i++;
		j++;
	}
	if (i > j)
		return (j);
	return (0);
}

char	*get_command(char **commands, int *i)
{
	char	*str;
	int		size;

	size = ft_strlen(commands[*i]) - 1;
	str = (char *)malloc((sizeof(char) * size) + 1);
	if (!str)
		msg_error("MAlloc Error");
	ft_strlcpy(str, commands[*i] + 1, size + 1);
	while (commands[*i] && commands[*i][size - 1] != '\'' )
	{
		(*i)++;
		str = ft_strjoin(ft_strjoin(str, " "), commands[*i]);
		size = ft_strlen(commands[*i]);
	}
	if (str[ft_strlen(str) - 1] == '\'')
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}

void	ft_split_by_quotes(char ***commands, int sz)
{
	int		i;
	char	**out;
	int		j;

	i = 0;
	j = 0;
	out = (char **) malloc((sizeof(char *) * sz) + 1);
	while ((*commands)[i])
	{
		if ((*commands)[i][0] == '\'')
			out[j++] = get_command(*commands, &i);
		else
			out[j++] = ft_strdup((*commands)[i]);
		i++;
	}
	out[j] = NULL;
	j = 0;
	while ((*commands)[j])
	{
		free((*commands)[j]);
		j++;
	}
	free(*commands);
	*commands = out;
}
