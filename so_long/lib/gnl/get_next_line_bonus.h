/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:30:50 by riosorio          #+#    #+#             */
/*   Updated: 2023/06/28 17:45:58 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	join_new_line(char **new_line, char *mem);
void	save_reminder(char **mem, size_t i, char **line);
size_t	check_end(char *str);
void	clean_mem(char **mem);

#endif
