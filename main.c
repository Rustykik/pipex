/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 04:08:45 by rusty             #+#    #+#             */
/*   Updated: 2022/01/23 04:10:18 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex_all_info;

	if ((argc <= 5 && ft_strncmp(argv[1], "here_doc", 9)) || argc <= 6)
	{
		ft_printf("Invalid arguments\n");
		exit(-1);
	}
	pipex_all_info = (t_pipex *)ft_calloc(sizeof(t_pipex), 1);
	if (!pipex_all_info)
		error_exit_nofree(strerror(errno));
	init_pipex(pipex_all_info, argc, argv, envp);
	pipex(pipex_all_info, argc, argv);
}
