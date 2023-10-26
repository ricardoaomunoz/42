/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:17:32 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/28 17:43:38 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **mem)
{
	size_t	i;
	int		r;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	i = 0;
	r = 1;
	join_new_line(&line, *mem);
	clean_mem(mem);
	while (i == 0 && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if ((r == 0 && !(*line)) || r == -1)
		{
			clean_mem(&line);
			return (NULL);
		}
		(buffer)[r] = '\0';
		join_new_line(&line, buffer);
		i = check_end(line);
	}
	if (i != 0)
		save_reminder(mem, i - 1, &line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(fd, &mem[fd]));
}
