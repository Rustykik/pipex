/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:23:43 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 02:46:33 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}

static void	open_infile(t_pipex *pipex, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit_free(pipex, strerror(errno));
	pipex->fd[0] = fd;
	pipex->i = 2;
}

void	here_doc_input(t_pipex *pipex, char **argv)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("> ", 2);
		line = ft_get_next_line(0);
		if (!line)
			error_exit_free(pipex, strerror(errno));
		if (!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
			break ;
		ft_putstr_fd(line, 1);
		free(line);
	}
	free(line);
	exit(0);
}

void	here_doc_pipe(t_pipex *pipex, char **argv)
{
	pid_t	pid;

	pipex->i = 3;
	pipex->here_doc = 1;
	if (pipe(pipex->fd))
		error_exit_free(pipex, strerror(errno));
	pid = fork();
	if (pid < 0)
		error_exit_free(pipex, strerror(errno));
	if (pid > 0)
	{
		dup2(pipex->fd[0], 0);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		waitpid(pid, NULL, 0);
	}
	else
	{
		dup2(pipex->fd[1], 1);
		close(pipex->fd[0]);
		close(pipex->fd[1]);
		here_doc_input(pipex, argv);
	}
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		here_doc_pipe(pipex, argv);
	else
		open_infile(pipex, argv);
	pipex->envp = envp;
	pipex->argc = argc;
}
