/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:47:39 by marvin            #+#    #+#             */
/*   Updated: 2019/02/05 18:27:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>
#include <unistd.h>

int				ft_execvp(const char *filename, char *const argv[])
{
	if (ft_strchr(filename, '/') != NULL)
	{
		execve(filename, argv, __environ);
		return (-1);
	}
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

int 			ms_exec(char **args)
{
	unsigned long hash;

	hash = sbdm((unsigned char *)args[0]) / MAP_SIZE;
	while (hash < MAP_SIZE && g_map[hash].name != NULL)
	{
		if (ft_strcmmp(g_map[hash].name, args[0]) == 0)
			return(g_map[hash].f(args));
		hash++;
	}
	return(ms_launcher(args));
}
