/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:47:39 by marvin            #+#    #+#             */
/*   Updated: 2019/02/03 02:58:13 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>
#include <unistd.h>

int				ft_execvp(const char *path, char *const argv[])
{
	if (ft_strchr(path, '/') != NULL)

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
	if (g_map[hash].name != NULL)
		return(g_map[hash].f(args));
	else
		return(ms_launcher(args));
	return (1);
}
