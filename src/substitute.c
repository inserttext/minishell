#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <unistd.h>

#define ENVC "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"

char	*getvalue(char **str, size_t len)
{
	char *value;
	char t;

	t = (*str)[len];
	(*str)[len] = '\0';
	value = __getenv(*str);
	(*str)[len] = t;
	*str += len;
	return (value);
}

char	*cashmoney(char **str)
{
	size_t 		len;

	if ((*str)[1] == '$')
	{
		*str += 2;
		return (ft_strdup(g_pid));
	}
	else if ((len = ft_strspn(++(*str), ENVC)) == 0)
		return (ft_strdup("$"));
	else
		return(ft_strdup(getvalue(str, len)));
}

char	*next(char **str)
{
	char		*dup;
	size_t		len;

	if ((*str)[0] == '$')
		return (cashmoney(str));
	len = ft_strcspn(*str, "$");
	dup = (char *)malloc((len + 1) * sizeof(char));
	ft_memcpy(dup, *str, len);
	dup[len] = '\0';
	*str += len;
	return (dup);
}

char	*generate(char *str)
{
	char *new;
	char *tmp;
	char *nxt;

	if (str[0] == '~' && (str[1] == '/' || str[1] == '\0'))
	{
		new = ft_strdup(__getenv("HOME"));
		str += str[1] == '\0' ? 1 : 2;
	}
	else
		new = (char *)ft_calloc(1, sizeof(char));
	while (*str != '\0')
	{
		tmp = new;
		nxt = next(&str);
		new = ft_strjoin(2, new, nxt);
		free(nxt);
		free(tmp);
	}
	return (new);
}

void	substitute(char **tok)
{
	while (*tok != NULL)
	{
		*tok = generate(*tok);
		tok++;
	}
}
