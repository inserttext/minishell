/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:30 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:52:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

#define ENVIRON extern char **environ

ENVIRON;
size_t	g_env_size;
char	**g_environ;
pid_t	g_pid;

static size_t	get_env_size(void)
{
	size_t len;

	len = 0;
	while (environ[len] != NULL)
		len++;
	return (len);
}

static void		env_cpy(void)
{
	size_t i;

	i = 0;
	g_environ = (char **)ft_calloc(g_env_size + 1, sizeof(char *));
	while (environ[i] != NULL)
	{
		g_environ[i] = ft_strdup(environ[i]);
		i++;
	}
}

static void		del_env(void)
{
	size_t i;

	i = 0;
	while (g_environ[i] != NULL)
	{
		free(g_environ[i]);
		i++;
	}
	free(g_environ);
}

int				main(void)
{
	g_env_size = get_env_size();
	g_pid = getpid();
	env_cpy();
	ms_loop();
	del_env();
	return (0);
}
