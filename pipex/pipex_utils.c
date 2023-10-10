/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:04:59 by riosorio          #+#    #+#             */
/*   Updated: 2023/09/23 17:20:05 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_env(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	change_fd(int fd, int x)
{
	if (dup2(fd, x) == -1)
		msg_error("Error dup");
	close(fd);
}

void	check_last(int process, int fd[2], int outFile)
{
	if (process != 1)
	{
		if (pipe(fd) == -1)
			msg_error("Error pipe");
		change_fd(fd[1], 1);
	}
	else
		change_fd(outFile, 1);
}

void	msg_error(char *msg)
{
	perror(msg);
	exit (1);
}

void	ft_check_files(char *readFile, char *writeFile, int (fd)[2])
{
	if (access(readFile, F_OK) != 0)
		msg_error("No infile");
	fd[0] = open(readFile, O_RDONLY);
	if (fd[0] < 0)
		msg_error("Error Infile");
	fd[1] = open(writeFile, O_TRUNC | O_CREAT | O_WRONLY, 0666);
	if (fd[1] < 0)
		msg_error("Error OutFile");
}
