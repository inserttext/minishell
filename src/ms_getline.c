/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:31 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

#define RSIZE 512U

static char	*g_storep = 0;
static char	*g_store = 0;

static void	extend(char **m, ssize_t *size, ssize_t need, ssize_t filled)
{
	char	*new;

	if (need < *size * 2)
		need = *size * 2;
	new = (char *)malloc((size_t)need * sizeof(char));
	ft_memcpy(new, *m, (size_t)filled);
	*size = need;
	free(*m);
	*m = new;
}

static void	storefn(char *buf)
{
	size_t len;

	len = ft_strlen(buf);
	g_storep = (char *)malloc(sizeof(char) * (len + 1));
	ft_memcpy(g_storep, buf, len);
	g_storep[len] = '\0';
	g_store = g_storep;
}

static int	recall(char **line, ssize_t *size, ssize_t *fill)
{
	char	*c;
	ssize_t	need;

	if ((c = ft_strchr(g_store, '\n')) != NULL)
		need = (ssize_t)((uintptr_t)c - (uintptr_t)g_store) + 1;
	else
		need = (ssize_t)ft_strlen(g_store);
	if (need > *size)
		extend(line, size, need, 0);
	ft_memcpy(*line, g_store, (size_t)need);
	if (*(g_store += need) == '\0')
	{
		free(g_storep);
		g_store = NULL;
	}
	*fill = need;
	(*line)[need] = '\0';
	return (!!c);
}

static void	aux(char **c, ssize_t *need, char *buf)
{
	if ((*c = ft_strchr(buf, '\n')) != NULL)
	{
		if (*need > (ssize_t)((uintptr_t)*c - (uintptr_t)buf) + 1)
			storefn(*c + 1);
		*need = (ssize_t)((uintptr_t)*c - (uintptr_t)buf) + 2;
	}
	else if (*need < RSIZE)
		exit(0);
}

ssize_t		ms_getline(char **line)
{
	char	*c;
	char	buf[RSIZE + 1];
	ssize_t	size;
	ssize_t	fill;
	ssize_t	need;

	fill = 0;
	size = RSIZE + 1;
	*line = (char *)malloc((size_t)size * sizeof(char));
	if (g_store != NULL)
		if (recall(line, &size, &fill) != 0)
			return (fill);
	while ((need = read(STDIN_FILENO, buf, RSIZE)) > 0)
	{
		buf[need] = '\0';
		aux(&c, &need, buf);
		if (need >= size)
			extend(line, &size, need, fill);
		ft_memcpy(*line, buf, (size_t)need);
		fill += need - 1;
		if (c != NULL)
			break ;
	}
	(*line)[fill] = '\0';
	return (fill);
}
