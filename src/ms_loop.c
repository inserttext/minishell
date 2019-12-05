/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:32 by marvin            #+#    #+#             */
/*   Updated: 2019/08/28 09:50:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	delete(char **mem, char *line)
{
	size_t i;

	i = 0;
	while (mem[i] != NULL)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	free(line);
}

void	ms_loop(void)
{
	char	*line;
	char	**tok;
	int		loop;

	loop = 1;
	while (loop >= 0)
	{
		write(STDOUT_FILENO, "$> ", 3);
		if (ms_getline(&line) == 0)
			return ;
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		tok = tokenize(line);
		if (tok == NULL)
		{
			free(line);
			continue;
		}
		substitute(tok);
		loop = launcher(tok);
		delete(tok, line);
	}
}
