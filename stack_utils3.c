/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:29:45 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 16:09:10 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = -1;
	size = ps_strlen(s1) + ps_strlen(s2);
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i] != '\0')
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

char	*bigstart(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	i = 0;
	slen = ps_strlen(s);
	if (start >= slen)
		return (bigstart());
	if (len > slen - start)
		len = slen - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
