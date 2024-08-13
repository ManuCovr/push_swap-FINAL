/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mtmpfb@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:53 by mde-maga          #+#    #+#             */
/*   Updated: 2024/07/30 20:28:28 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	putstr("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	putstr("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	putstr("ss\n");
}
