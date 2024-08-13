/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maga <mde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:50:11 by mde-maga          #+#    #+#             */
/*   Updated: 2024/08/13 15:42:31 by mde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*i;

	i = malloc(nmemb * size);
	if (!i)
		return (NULL);
	ft_bzero(i, nmemb * size);
	return (i);
}

static char	**ft_cut(char **argv)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	**res;

	i = 0;
	temp = ft_calloc(2, 1);
	while (argv[i])
	{
		temp2 = ft_strjoin(temp, argv[i]);
		free(temp);
		temp = ft_strjoin(temp2, " ");
		free(temp2);
		i++;
	}
	res = split(temp, ' ');
	free(temp);
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**luffy;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		putstr_fd("Error\n", 2);
		return (1);
	}
	luffy = ft_cut(argv + 1);
	init_stack_a(&a, luffy);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_split(luffy);
	free_my_mans(&a);
	return (0);
}
