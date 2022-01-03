/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 19:25:36 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/01 19:25:36 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_empty(t_stack **start)
{
	if (*start == NULL)
		return (1);
	return (0);
}

int	top(t_stack **stack)
{
	return ((*stack)->n);
}

size_t	ft_find_min(t_stack *stack)
{
	int		min;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	min = stack->n;
	while (stack)
	{
		if (stack -> n < min)
		{
			min = stack -> n;
			j = i;
		}
		stack = stack -> next;
		i++;
	}
	return (j);
}

void	ft_sort_stack(t_stack **a, t_stack **b)
{
	size_t	i;
	size_t	size;

	size = ft_size(a);
	while (!ft_empty(a))
	{
		i = ft_find_min(*a);
		if (i > (size / 2))
		{
			i = size - i;
			while (i--)
				ft_reverse_rotate_stack(a, 'a');
		}
		else
			while (i--)
				ft_rotate_stack(a, 'a');
		ft_push_stack(a, b, 'b');
	}
	while (!ft_empty(b))
		ft_push_stack(b, a, 'a');
}

int main()
{
	t_stack *a;
	a = NULL;
	t_stack *b;
	b = NULL;
	for (int i = 0; i != 100; i++)
	{		
		int rd = rand() / 1000000;
		ft_push(&a, ft_stacknew(rd, 'a'));
	}
	//print(&a);
	//ft_sort_stack(&a, &b);
	ft_radix(&a, &b);
	while (!ft_empty(&a) && a->next)
		free(ft_pop_bottom(&a));
	free(a);
	free(b);
	//print(&a);
}
