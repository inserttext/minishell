/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:47:39 by marvin            #+#    #+#             */
/*   Updated: 2019/01/30 23:21:09 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include "builtin_map.c"
#include <sys/wait.h>

int 			ms_exec(char **args)
{
	return (1);
}

int 			ms_launcher(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, g_environ) == -1)
			ft_fprintf(2, "yah dun goofed\n");
		exit(0);
	}
	else if (pid < 0)
		ft_fprintf(2, "yah dun goofed\n");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
