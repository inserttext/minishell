/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:39:39 by marvin            #+#    #+#             */
/*   Updated: 2020/01/17 15:13:49 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

static void	changedir(char *dir)
{
	char *tmp;

	if (dir == NULL)
		return;
	chdir(dir);
	ms_setenv("OLDPWD", ms_getenv("PWD"), 1);
	ms_setenv("PWD", tmp = getcwd(NULL, 0), 1);
	free(tmp);
}

static void prev()
{
	char	*cwd;
	size_t	len;

	changedir(ms_getenv("OLDPWD"));
	cwd = getcwd(NULL, 0);
	len = ft_strlen(ms_getenv("HOME"));
	if (ft_strncmp(cwd, ms_getenv("HOME"), len) == 0)
		cwd[len - 1] = '~';
	else
		len = 1;
	ft_printf("%s\n", cwd + len - 1);
	free(cwd);
}


int			builtin_cd(char **tok)
{
	DIR *dir;

	if (tok[1] == NULL)
	{
		if (ms_getenv("HOME") != NULL)
			changedir(ms_getenv("HOME"));
	}
	else if (*((uint16_t *)tok[1]) == *(uint16_t *)"-")
		prev();
	else if (access(tok[1], R_OK) == 0)
	{
		if ((dir = opendir(tok[1])) != NULL)
		{
			changedir(tok[1]);
			closedir(dir);
		}
		else
			ft_printf("cd: not a directory: %s\n", tok[1]);
	}
	else
		ft_printf("cd: no such file or directory: %s\n", tok[1]);
	return (0);
}
