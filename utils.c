/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:09:42 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 00:10:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*reall_join(char *s1, char *s2)
{
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	ret = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_strlcpy(ret + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (ret);
}

char	*get_cmd_name(char *cmd)
{
	char	**args;
	char	*cmd_name;

	args = ft_split(cmd, ' ');
	if (!args)
		return (NULL);
	cmd_name = ft_strdup(args[0]);
	if (!cmd_name)
		return (NULL);
	free_split(args);
	return (cmd_name);
}

char	*check_path(char *cmd_name, char **cmd_paths)
{
	int		i;
	char	*path;
	char	*full_cmd;

	i = -1;
	while (cmd_paths[++i])
	{
		path = ft_strjoin(cmd_paths[i], "/");
		if (!path)
			return (NULL);
		full_cmd = ft_strjoin(path, cmd_name);
		free(path);
		if (!full_cmd)
			return (NULL);
		if (!access(full_cmd, F_OK))
			return (full_cmd);
		free(full_cmd);
	}
	return (NULL);
}

void	execute_command(char *cmd, t_pipex *pipex)
{
	char	*full_cmd;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
		error_exit_free(pipex, strerror(errno));
	full_cmd = find_comand(cmd, pipex);
	execve(full_cmd, args, pipex->envp);
	error_exit_execute(pipex);
}
