#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

int	__env(char **tok)
{
	const char **env;

	(void)tok;
	env = (const char **)g_environ;
	while (*env != NULL)
	{
		ft_printf("%s\n", *env);
		env++;
	}
	return (0);
}
