/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:09:16 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 02:20:23 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*try_to_access(char *cmd, char **cmd_paths)
{
	char	*full_cmd;
	char	*cmd_name;

	cmd_name = get_cmd_name(cmd);
	if (!cmd_name)
		return (NULL);
	else if (cmd_name[0] == '/' || cmd_name[0] == '.' || cmd_name[0] == '~')
		return (cmd_name);
	full_cmd = check_path(cmd_name, cmd_paths);
	free(cmd_name);
	return (full_cmd);
}

char	*find_comand(char *cmd, t_pipex *pipex)
{
	int		i;
	char	**cmd_paths;
	char	*full_cmd;

	i = -1;
	while (pipex->envp[++i])
	{
		if (!ft_strncmp(pipex->envp[i], "PATH=", 5))
			break ;
	}
	cmd_paths = ft_split(&pipex->envp[i][5], ':');
	if (!cmd_paths)
		error_exit_free(pipex, strerror(errno));
	full_cmd = try_to_access(cmd, cmd_paths);
	free_split(cmd_paths);
	return (full_cmd);
}

static void	pipes_exec(t_pipex *pipex, char *cmd)
{
	int		fd[2];
	pid_t	pid;
	int		wstatus;

	if (pipe(fd))
		error_exit_free(pipex, strerror(errno));
	pid = fork();
	if (pid < 0)
		error_exit_free(pipex, strerror(errno));
	if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(pid, &wstatus, 0);
		if (WEXITSTATUS(wstatus) == EXIT_FAILURE)
			error_exit_execute(pipex);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_command(cmd, pipex);
	}
}

void	pipex(t_pipex *pipex, int argc, char **argv)
{
	int	fd;

	--pipex->i;
	if (pipex->here_doc)
	{
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND);
		if (fd < 0)
			error_exit_free(pipex, strerror(errno));
	}
	else
	{
		dup2(pipex->fd[0], 0);
		close(pipex->fd[0]);
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
		if (fd < 0)
			error_exit_free(pipex, strerror(errno));
	}
	while (++pipex->i < argc - 2)
		pipes_exec(pipex, argv[pipex->i]);
	dup2(fd, 1);
	close(fd);
	execute_command(argv[argc - 2], pipex);
}
