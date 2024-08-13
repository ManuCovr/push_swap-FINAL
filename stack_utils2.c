/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:13:26 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/09 16:12:52 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_strlen(const char *s)
{
	size_t	ans;

	ans = 0;
	if (!s)
		return (0);
	while (s[ans])
		++ans;
	return (ans);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	putstr_fd(char *s, int fd)
{
	if (!s || *s == '\0' || fd < 0)
		return ;
	write(fd, s, ps_strlen(s));
}
