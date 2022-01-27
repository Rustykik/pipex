/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:16:18 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 00:23:53 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit_nofree(char *strerr)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(strerr, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void	error_exit_free(t_pipex *pipex, char *strerr)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (pipex->here_doc_line)
		free(pipex->here_doc_line);
	free(pipex);
	error_exit_nofree(strerr);
}

void	error_exit_execute(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (pipex->here_doc_line)
		free(pipex->here_doc_line);
	free(pipex);
	ft_putstr_fd("pipex: command not found\n", 2);
	exit(127);
}
