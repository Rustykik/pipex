/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:10:54 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 00:28:01 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
// # include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		fd[2];
	char	**envp;
	char	**argv;
	int		argc;
	int		here_doc;
	char	*here_doc_line;
	int		i;
	char	*limiter;

}	t_pipex;

/* pipex.c */
char	*find_comand(char *cmd, t_pipex *pipex);
void	pipex(t_pipex *pipex, int argc, char **argv);

/* errors.c */
void	error_exit_nofree(char *strerr);
void	error_exit_free(t_pipex *pipex, char *strerr);
void	error_exit_execute(t_pipex *pipex);

/* utils.c */
char	*reall_join(char *s1, char *s2);
char	*get_cmd_name(char *cmd);
char	*check_path(char *cmd, char **cmd_paths);
void	execute_command(char *cmd, t_pipex *pipex);

/* inits_and_frees */
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
void	free_split(char **split);

#endif
