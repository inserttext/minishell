/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:40:35 by marvin            #+#    #+#             */
/*   Updated: 2019/08/13 14:55:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char		*brack(char *s, char **save)
{
	char *end;
	char *d;

	d = " ";
	if (*s == '"' || *s == '\'')
	{
		d[0] = *s;
		s++;
	}
	end = s;
	while (1)
	{
		end += ft_strcspn(end, d);
		if (end[-1] == '\\')
			continue;
		else
			break;
	}
	*end = '\0';
	*save = end + 1;
	return (s);
}

char		*ms_strtok(char **s)
{
	static char	*olds;

	if (*s != NULL)
		olds = *s;
	olds += ft_strspn(olds, " ");
	if (*olds == '\0')
		return (NULL);
	return (brack(olds, &olds));
}
