/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:35 by marvin            #+#    #+#             */
/*   Updated: 2020/01/15 13:44:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	*brack(char *s)
{
	char *end;
	char d[2];

	d[0] = *s++;
	d[1] = '\0';
	end = s;
	while (*((end += ft_strcspn(end, d))) == '\\' && *end != '\0')
		;
	return (end);
}

char		*ms_strtok(char *s)
{
	static char	*olds = NULL;
	char		*end;

	if (s == NULL)
		s = olds;
	s += ft_strspn(s, " \t");
	if (*s == '\0')
	{
		olds = s;
		return (NULL);
	}
	if (*s == '"' || *s == '\'')
	{
		end = brack(s);
		s++;
	}
	else
		end = s + ft_strcspn(s, " \t");
	olds = end + (*end == '\0' ? 0 : 1);
	*end = '\0';
	return (s);
}
