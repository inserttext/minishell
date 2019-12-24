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
	size_t oldl;

	oldl = *t_len;
	*t_len += 5;
	new = (char **)ft_calloc(*t_len + 1, sizeof(char *));
	ft_memcpy(new, tok, oldl * sizeof(char *));
	free(tok);
	return (new);
}

char	**tokenize(char *str)
{
	char	**tok;
	size_t	t_len;
	size_t	i;

	i = 0;
	t_len = 5;
	tok = (char **)ft_calloc(t_len + 1, sizeof(char *));
	tok[i] = ms_strtok(str);
	while (tok[i] != NULL)
	{
		i++;
		if (i >= t_len)
			tok = tok_realloc(tok, &t_len);
		tok[i] = ms_strtok(NULL);
	}
	return (tok);
}
