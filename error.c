/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:49:31 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 16:06:04 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if ((str_n[i] == '+' && str_n[i + 1] == '0')
		|| (str_n[i] == '-' && str_n[i + 1] == '0'))
		return (1);
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	while (str_n[i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_dup(t_stack_node *a, int n) // checks for duplicate inputs
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_my_mans(t_stack_node **stack) // frees stacks in case of error
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		curr->nbr = 0;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	free_errors(char *str, t_stack_node **a, char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free(split);
		split = NULL;
	}
	free_my_mans(a);
	putstr_fd(str, 2);
	exit(1);
}
