/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 02:38:10 by tingo             #+#    #+#             */
/*   Updated: 2019/03/30 09:30:53 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

#define ACCEPT "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

char		*__strjoin_free(char *a, char *b)
{
	char *new;

	new = ft_strjoin(2, a, b);
	free(a);
	return (new);
}

static char *aux(char *new, char *a)
{
	char	*sym;
	char	*z;

	while (a != NULL)
	{
		z = a + ft_strspn(a, ACCEPT);
		if ((z = ft_strchr(z, '$')) != NULL)
			*z++ = '\0';
		sym = __ms_builtin_getenv(a);
		new = __strjoin_free(sym, a + ft_strspn(a, ACCEPT));
		a = z;
	}
	return (new);
}

char		*__ms_tok_sub(char *tok)
{
	char	*sym;
	char	*new;
	char	*a;

	new = NULL;
	if ((a = ft_strchr(tok, '$')) != NULL)
		*a++ = '\0';
	if (tok[0] == '~' && (tok[1] == '\0' || tok[1] == '/'))
	{
		sym = __ms_builtin_getenv("HOME");
		if (tok[1] == '\0')
			new = ft_strdup(sym);
		else
			new = ft_strjoin(2, sym, tok + 1);
	}
	else
		new = ft_strdup(tok);
	new = aux(new, a);
	return (new);
}
