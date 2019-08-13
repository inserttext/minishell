#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

#define ENVC "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"

int	__export(char **tok)
{
	char *name;
	char *value;

	if (tok[1] == NULL || (value = ft_strchr(tok[1], '=') + 1) == NULL)
		return (0);
	value += ft_strspn(value, "=");
	name = ft_strtok(tok[1], "=");
	if (ft_strspn(name, ENVC) < ft_strlen(name))
	{
		ft_printf("export: not valid in this context: %s\n", name);
		return (0);
	}
	__setenv(name, value, 1);
	return (0);
}
