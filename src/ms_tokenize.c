/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:07:52 by tingo             #+#    #+#             */
/*   Updated: 2019/03/30 09:26:11 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include "ms_tokenize2.c"

#define TOK_DELIM " \t\r\n\a"
#define TOK_SIZE 64

static char *g_p;

size_t	__ms_brackets(char **s, size_t *len)
{
	char	c;
	char	*line;
	char	*end;
	char	*tmp;
	size_t	llen;

	c = **s;
	*s += 1;
	while ((end = ft_strchr(*s, c)) == NULL)
	{
		llen = ms_getline(&line);
		tmp = (char *)malloc(sizeof(char) * (llen + *len + 1));
		ft_memcpy(tmp, g_p, *len);
		ft_memcpy(tmp + *len, line, llen);
		*s = tmp + (*s - g_p);
		free(g_p);
		free(line);
		*len += llen;
		g_p = tmp;
		g_p[*len] = '\0';
	}
	*end = '\0';
	return (end - g_p + 2);
}

char	*__ms_tok_r(char *s, size_t *offset, size_t *len)
{
	char *end;

	if (s == NULL)
		s = g_p + *offset;
	if (*s == '\0')
		return (NULL);
	s += ft_strspn(s, TOK_DELIM);
	if (*s == '\0')
		return (NULL);
	if (*s == '\"' || *s == '\'')
	{
		*offset = __ms_brackets(&s, len);
		return (s);
	}
	end = s + ft_strcspn(s, TOK_DELIM);
	if (*end == '\0')
	{
		*offset = end - g_p + 1;
		return (s);
	}
	*end = '\0';
	*offset = end - g_p + 1;
	return (s);

}

char	*ms_tok(char *line, size_t *len)
{
	static size_t olds;

	return(__ms_tok_r(line, &olds, len));
}

char	**finalize(char **line, size_t *offsets, size_t len)
{
	char	**ret;
	size_t	i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		ret[i] = __ms_tok_sub(offsets[i] + g_p);
		i++;
	}
	*line = g_p;
	ret[len] = NULL;
	free(offsets);
	return (ret);
}

char	**ms_tokenize(char **line, size_t len)
{
	char	*token;
	size_t	*t;
	size_t	*offset;
	size_t	size;
	size_t	i;

	i = 1;
	g_p = *line;
	size = TOK_SIZE + 1;
	offset = (size_t *)malloc(sizeof(size_t) * TOK_SIZE);
	token = ms_tok(*line, &len);
	offset[0] = token - *line;
	while ((token = ms_tok(NULL, &len)) != NULL)
	{
		offset[i++] = token - g_p;
		if (i == size)
		{
			size += TOK_SIZE;
			t = (size_t *)malloc(sizeof(size_t) * TOK_SIZE);
			ft_memcpy(t, offset, sizeof(size_t) * i);
			free(offset);
			offset = t;
		}
	}
	return (finalize(line, offset, i));
}
