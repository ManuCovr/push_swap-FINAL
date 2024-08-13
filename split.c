/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:43 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 16:08:50 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**freethem(char **ss)
{
	int	i;

	i = 0;
	while (ss[i] != 0)
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (NULL);
}

static int	words(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wc++;
		i++;
	}
	return (wc);
}

static int	letters(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			break ;
		i++;
		l++;
	}
	return (l + 1);
}

char	**split(char *s, char c)
{
	int		i;
	int		st;
	char	**res;

	res = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!res)
		return (NULL);
	st = 0;
	i = 0;
	while (s[st] != '\0')
	{
		if (s[st] != c)
		{
			res[i] = ft_substr(s, st, letters(s, c, st));
			if (!res[i++])
				return (freethem(res));
			st += letters(s, c, st);
		}
		else
			st++;
	}
	res[i] = NULL;
	return (res);
}
