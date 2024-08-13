/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:37 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 15:29:24 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_or_rev_rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node,
						void (*rotate_func)(t_stack_node**, t_stack_node**))
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_func(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above && cheapest_node->target_node->above)
		rotate_or_rev_rotate_both(a, b, cheapest_node, rr);
	else if (!(cheapest_node->above) && !(cheapest_node->target_node->above))
		rotate_or_rev_rotate_both(a, b, cheapest_node, rrr);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa (a, b);
}

static void	min_to_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int		len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}
