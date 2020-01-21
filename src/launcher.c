/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:29 by marvin            #+#    #+#             */
/*   Updated: 2019/08/15 17:02:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>

static struct s_func	tbl[128] = {
	[5] = {"exit", &builtin_exit},
	[24] = {"env", &builtin_env},
	[36] = {"echo", &builtin_echo},
	[58] = {"setenv", &builtin_setenv},
	[60] = {"unset", &builtin_unsetenv},
	[97] = {"export", &builtin_setenv},
	[98] = {"cd", &builtin_cd},
};

static unsigned long	hash(unsigned char *str)
{
	unsigned long hash;

	hash = 5381;
	while (*str)
	{
		hash = ((hash << 5U) + hash) ^ *str;
		str++;
	}
	return (hash);
}

static int				forkexec(char *run, char **tok)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(run, tok, g_environ);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		printf("msh: unable to fork process\n");
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}

static int				searchpath(char **tok)
{
	char *fullpath;
	char *path;
	char *run;

	if ((fullpath = ft_strdup(ms_getenv("PATH"))) == NULL)
		path = NULL;
	else
		path = ft_strtok(fullpath, ":");
	while (path != NULL)
	{
		run = ft_strjoin(3, path, "/", tok[0]);
		if (access(run, X_OK) == 0)
		{
			forkexec(run, tok);
			free(run);
			break ;
		}
		free(run);
		path = ft_strtok(NULL, ":");
	}
	if (path == NULL)
		ft_printf("msh: command not found: %s\n", tok[0]);
	free(fullpath);
	return (0);
}

int						launcher(char **tok)
{
	unsigned long	hashed;
	int				ret;

	ret = 1;
	hashed = hash((unsigned char *)tok[0]) % 128;
	if (tbl[hashed].name != NULL && ft_strcmp(tok[0], tbl[hashed].name) == 0)
		ret = tbl[hashed].f(tok);
	else if (ft_strchr(tok[0], '/') != NULL)
	{
		if (access(tok[0], X_OK) == 0)
			ret = forkexec(tok[0], tok);
		else
			ft_printf("msh: command not found: %s\n", tok[0]);
	}
	else
		ret = searchpath(tok);
	return (ret);
}
