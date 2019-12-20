/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:35 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	**tok_realloc(char **tok, size_t *t_len)
{
	char **new;
	size_t old;

	old = *t_len;
	*t_len += 5;
	new = (char **)ft_calloc(*t_len + 1, sizeof(char *));
	ft_memcpy(new, tok, old * sizeof(char *));
	free(tok);
	return (new);
}

char	**tokenize(char **str, ssize_t len)
{
	char	**tok;
	char	*store;
	size_t	t_len;
	size_t	i;

	i = 0;
	t_len = 5;
	tok = (char **)ft_calloc(t_len + 1, sizeof(char *));
	tok[0] = (char *)(ms_strtok(str, &len) - *str);
	while ((store = ms_strtok(NULL, &len)) != NULL)
	{
		tok[++i] = (char *)(store - *str);
		if (i >= t_len)
			tok = tok_realloc(tok, &t_len);
	}
	i = 0;
	while (tok[i]) {
		tok[i] = (intptr_t)tok[i] + *str;
		++i;
	}
	return (tok);
}
