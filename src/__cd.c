#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/types.h>
#include <dirent.h>
static void	changedir(char *dir)
{
	chdir(dir);
	__setenv("OLDPWD", __getenv("PWD"), 1);
	__setenv("PWD", dir, 1);
}

int __cd(char **tok)
{
	DIR *dir;

	if (tok[1] == NULL && __getenv("HOME") != NULL)
		changedir(__getenv("HOME"));
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