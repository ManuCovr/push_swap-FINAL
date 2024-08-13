/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:14 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 16:08:07 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Errors

int				error_syntax(char *str_n);
int				error_dup(t_stack_node *a, int n);
void			free_my_mans(t_stack_node **stack);
void			free_errors(char *str, t_stack_node **a, char **split);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ps_strlen(const char *s);
void			free_split(char **argv);

//stacks

void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			putstr_fd(char *s, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*bigstart(void);
//Commands
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//Nodes

t_stack_node	*get_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			prep_for_push(t_stack_node **stack, \
				t_stack_node *top, \
				char stack_name);
void			putstr(char *str);
int				ft_isdigit(int c);
int				ft_strcmp(char *s1, char *s2);

#endif