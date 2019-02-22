/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenize2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 02:38:10 by tingo             #+#    #+#             */
/*   Updated: 2019/02/15 01:35:53 by tingo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

char	*__ms_tok_sub(char *tok)
{
	char	*sym;
	char	*new;

	if (tok[0] == '~' && (tok[1] == '\0' || tok[1] == '/'))
	{
		sym = __ms_builtin_getenv("HOME");
		if (tok[1] == '\0')
			new = ft_strdup(sym);
		else
			new = ft_strjoin(2, sym, tok + 1);
	}
	while (
	return (NULL);
}
