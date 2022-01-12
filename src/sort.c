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
	min = stack->index;
	while (stack)
	{
		if (stack -> index < min)
		{
			min = stack -> index;
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

	while (!ft_empty(a))
	{
		size = ft_size(a);
		i = ft_find_min(*a);
		if (i > (size / 2))
		{
			while (i++ != size)
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
