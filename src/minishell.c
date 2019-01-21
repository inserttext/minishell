/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 07:02:32 by tingo             #+#    #+#             */
/*   Updated: 2019/01/20 00:58:51 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

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
	while ((end = ft_strchr(*s + 1, c)) == NULL)
	{
		llen = ms_getline(&line);
		tmp = (char *)malloc(sizeof(char) * (llen + *len + 1));
		ft_memcpy(tmp, g_p, *len);
		ft_memcpy(tmp + *len, line, llen);
		*s = tmp + (*s - g_p);
		free(g_p);
		*len += llen;
		g_p = tmp;
		g_p[*len] = '\0';
	}
	*end = '\0';
	return (end - g_p + 2);
}

char	*__ms_tok_r(char *s, size_t *save_ptr, size_t *len)
{
	char *end;

	if (s == NULL)
		s = g_p + *save_ptr;
	if (*s == '\0')
		return (NULL);
	s += ft_strspn(s, TOK_DELIM);
	if (*s == '\0')
		return (NULL);
	if (*s == '\"' || *s == '\'')
	{
		*save_ptr = __ms_brackets(&s, len);
		return (s);
	}
	end = s + ft_strcspn(s, TOK_DELIM);
	if (*end == '\0')
	{
		*save_ptr = end - g_p + 1;
		return (s);
	}
	*end = '\0';
	*save_ptr = end - g_p + 1;
	return (s);

}

char	*ms_tok(char *line, size_t *len)
{
	static size_t olds;

	return(__ms_tok_r(line, &olds, len));
}

ssize_t	*ms_tokenize(char **line, size_t len)
{
	char	*token;
	ssize_t	*t;
	ssize_t	*offset;
	size_t	size;
	size_t	i;

	i = 1;
	size = TOK_SIZE + 1;
	offset = (ssize_t *)malloc(sizeof(ssize_t) * TOK_SIZE);
	token = ms_tok(*line, &len);
	offset[0] = token - *line;
	while ((token = ms_tok(NULL, &len)) != NULL)
	{
		offset[i] = token - *line;
		i++;
		if (i == size)
		{
			size += TOK_SIZE;
			t = (ssize_t *)malloc(sizeof(ssize_t) * TOK_SIZE);
			ft_memcpy(t, offset, sizeof(ssize_t) * i);
			free(offset);
			offset = t;
		}
	}
	offset[i] = -1;
	return (offset);
}

void	ms_loop()
{
	char	*line;
	size_t	len;
	ssize_t	*offset;

	/* while (1) */
	/* { */
		write(1, "$> ", 3);
		len = ms_getline(&line);
		g_p = line;
		offset = ms_tokenize(&line, len);
		for (int i = 0; offset[i] >= 0; i++) {
			printf("%lu = %s\n", offset[i], g_p + offset[i]);
		}

		free(line);
		free(offset);
	/* } */
}
