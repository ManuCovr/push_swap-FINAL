/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:47 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 15:52:43 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **arg)
{
	long	n;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (error_syntax(arg[i]))
			free_errors("Error, not a number\n", a, arg);
		n = ft_atol(arg[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors("Error, number too big/small\n", a, arg);
		if (error_dup(*a, (int)n))
			free_errors("Error, duplicate (or more) numbers\n", a, arg);
		append_node(a, (int)n);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
