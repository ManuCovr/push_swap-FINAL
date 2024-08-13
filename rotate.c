/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:28 by mde-maga          #+#    #+#             */
/*   Updated: 2024/07/30 20:26:29 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	putstr("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	putstr("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	putstr("rr\n");
}
