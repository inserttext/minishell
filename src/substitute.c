#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <unistd.h>

#define ENVCHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"

static char		*search(char *tok, char *str)
{
	char	*name;
	char	*new;
	size_t	len;

	len = ft_strspn(tok, ENVCHAR);
	name = (char *)malloc(len * sizeof(char));
	ft_memcpy(name, tok, len);
	name[len] = '\0';
	new = ft_strjoin(3, str, __getenv(name), tok + len);
	free(name);
	return (new);
}

static char		*parsenv(char *str)
{
	char	*new;
	char	*tok;
	int		fl;

	fl = 0;
	new = (char *)ft_calloc(1, sizeof(char));
	tok = ft_strtok(str, "$");
	while (tok != NULL)
	{
		str = new;
		if (fl == 0 && tok[0] == '~' && (tok[1] == '/' || tok[1] == '\0'))
			new = ft_strjoin(2, __getenv("HOME"), tok + 1);
		else if (ft_strspn(tok, ENVCHAR) == 0)
			new = ft_strjoin(3, new, "$", tok);
		else
			new = search(tok, new);
		free(str);
		tok = ft_strtok(NULL, "$");
		fl = 1;
	}
	return (new);
}

char	**substitute(char **tok)
{
	char **curr;

	curr = tok;
	while (*curr != NULL)
	{
		if (ft_strchr(*curr, '$') != NULL ||
			((*curr)[0] == '~' && ((*curr)[1] == '/' || (*curr)[1] == '\0')))
			*curr = parsenv(*curr);
		else
			*curr = ft_strdup(*curr);
		curr++;
	}
	return (tok);
}