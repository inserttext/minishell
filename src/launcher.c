/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:47:39 by marvin            #+#    #+#             */
/*   Updated: 2019/02/26 15:31:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>
#include <unistd.h>

char *test(const char *filename, const char *path)
{
	char	*file;
	size_t	plen;
	size_t	flen;

	plen = ft_strchr(path, ':') ? ft_strchr(path, ':') - path : ft_strlen(path);
	flen = ft_strlen(filename);
	file = (char *)malloc(sizeof(char) * (plen + flen) + 1);
	ft_memcpy(file, path, plen);
	ft_memcpy(file + plen, filename, flen);
	if (access(file, X_OK) == 0)
		return (file);
	free(file);
	return (NULL);
}

int				ft_execvp(const char *filename, char *const argv[])
{
	const char	*path;
	char		*tmpfile;
	int			ret;

	path = __ms_builtin_getenv("PATH");
	if (ft_strchr(filename, '/') != NULL)
	{
		execve(filename, argv, __environ);
		return (-1);
	}
	while ((tmpfile = test(filename, path)) == NULL)
	{
		if ((path = ft_strchr(path, ':')) == NULL)
			return (-1);
		++path;
	}
	ret = execve(tmpfile, argv, __environ);
	free(tmpfile);
	return (ret);
}

int 			ms_launcher(char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, g_environ) == -1)
			ft_fprintf(2, "unable to find file in path\n");
		exit(0);
	}
	else if (pid < 0)
		ft_fprintf(2, "fork issue\n");
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
		if (ft_strcmp(g_map[hash].name, args[0]) == 0)
			return(g_map[hash].f(args));
		hash++;
	}
	return(ms_launcher(args));
}
