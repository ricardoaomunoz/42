/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riosorio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:30:09 by riosorio          #+#    #+#             */
/*   Updated: 2023/09/23 17:20:04 by riosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

char	*get_path(char *env_path, char *command)
{
	char	**paths;
	int		x;
	int		exist;
	char	*tmp;

	x = 0;
	exist = 0;
	paths = ft_split(env_path, ':');
	while (paths[x] && !exist)
	{
		tmp = ft_strjoin(ft_strjoin(paths[x], "/"), command);
		if (access(tmp, F_OK) == 0)
			exist = 1;
		free(paths[x]);
		x++;
	}
	free(paths);
	if (!exist)
	{
		free(tmp);
		msg_error("command not found");
	}
	return (tmp);
}

void	run_child(int fd[2], char *cmd, char *env_path, int outFile)
{
	char	**commands;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	close(outFile);
	close(fd[0]);
	close(fd[1]);
	commands = ft_split(cmd, ' ');
	if (get_size(commands) > 0)
		ft_split_by_quotes(&commands, get_size(commands));
	path = get_path(env_path, *commands);
	if (execve(path, commands, NULL) == -1)
		msg_error("command not found");
	free(path);
	msg_error("Error execve");
}

void	exec_command(int process, char **argv, int outFile, char *env_path)
{
	int		i;
	int		pids;
	int		fd[2];

	i = 0;
	while (process > 0)
	{
		check_last(process, fd, outFile);
		pids = fork();
		if (pids == -1)
			msg_error("Error fork");
		if (pids == 0)
			run_child(fd, argv[i + 2], env_path, outFile);
		wait(NULL);
		if (process != 1)
			change_fd(fd[0], 0);
		i++;
		process--;
	}
	close(fd[0]);
	close(fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		files[2];
	int		process;
	char	*env_path;

	process = argc - 3;
	if (argc > 4)
	{
		ft_check_files(argv[1], argv[argc - 1], files);
		if (dup2(files[0], 0) == -1)
			msg_error("Error dup");
		close(files[0]);
		env_path = get_path_env(envp);
		exec_command(process, argv, files[1], env_path);
	}
	else
		msg_error("Error should be more than 4 arguments\n");
	return (0);
}
