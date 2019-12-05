/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:39:39 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

static void	changedir(char *dir)
{
	chdir(dir);
	ms_setenv("OLDPWD", ms_getenv("PWD"), 1);
	ms_setenv("PWD", getcwd(NULL, 0), 1);
}

int			builtin_cd(char **tok)
{
	DIR *dir;

	if (tok[1] == NULL)
	{
		if (ms_getenv("HOME") != NULL)
			changedir(ms_getenv("HOME"));
		else
			return (0);
	}
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
