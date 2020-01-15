/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:32 by marvin            #+#    #+#             */
/*   Updated: 2020/01/15 13:45:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int		brack(const char *line)
{
	size_t	pos;
	char	d[2];

	d[1] = '\0';
	while (line[pos = ft_strcspn(line, "\"'")] == '"' || line[pos] == '\'')
	{
		d[0] = line[pos];
		line += pos + 1;
		while (line[pos = ft_strcspn(line, d)] == d[0] && line[pos] == '\\')
			line += pos + 1;
		line += pos + 1;
		if (line[-1] != d[0])
			return (*line - 34 == 5 ? 2 : 3);
	}
	return (0);
}

int		verify(const char *line)
{
	size_t	len;
	int		ret;

	ret = 0;
	if (*line == '\0' || *line == '\n')
		return (0);
	else
		ret = brack(line);
	len = ft_strlen(line);
	if (ret == 0 && len >= 2 && line[len - 1] == '\n' && line[len - 2] == '\\')
		ret = 1;
	return (ret);
}

char	*getinput(void)
{
	char	*input;
	char	*line;
	char	*tmp;
	int		ver;

	ms_getline(&input);
	while ((ver = verify(input)))
	{
		if (ver == 2)
			write(STDOUT_FILENO, "quote", 5);
		else if (ver == 3)
			write(STDOUT_FILENO, "dquote", 6);
		write(STDOUT_FILENO, "> ", 2);
		ms_getline(&line);
		tmp = input;
		input = ft_strjoin(2, input, line);
		free(tmp);
		free(line);
	}
	return (input);
}

void	cleanup(char **tok, char *line)
{
	size_t	i;

	free(line);
	i = 0;
	while (tok[i])
		free(tok[i++]);
	free(tok);
}

void	ms_loop(void)
{
	char	*line;
	char	**tok;
	int		loop;

	loop = 0;
	while (loop >= 0)
	{
		write(STDOUT_FILENO, "$> ", 3);
		if (*(line = getinput()) == '\0' || *line == '\n')
		{
			if (*line == '\0')
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			continue;
		}
		line[ft_strlen(line) - 1] = '\0';
		tok = tokenize(line);
		substitute(tok);
		loop = launcher(tok);
		cleanup(tok, line);
	}
}
