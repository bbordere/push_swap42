/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:59:19 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/06 14:04:53 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_index_min(t_stack **stack)
{
	int	index;
	t_stack	*temp;

	temp = *stack;
	index = temp->index;
	while (temp)
	{
		if (temp->index < index)
			index = temp->index;
		temp = temp->next;
	}
	return (index);
}

int		ft_distance(t_stack **stack, int index)
{
	t_stack	*temp;
	int		distance;

	distance = 0;
	temp = *stack;
	while (temp->index != index)
	{
		distance++;
		temp = temp->next;
	}
	return (distance);
}

void	ft_sort_two(t_stack **stack)
{
	if (!ft_is_sorted(stack))
		ft_rotate_stack(stack, 'a');
}

void	ft_sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bottom;

	while (!ft_is_sorted(stack))
	{
		top = (*stack) -> n;
		mid = (*stack) -> next -> n;
		bottom = (*stack) -> next -> next -> n;
		if (top > mid && mid > bottom)
			ft_swap_stack(stack, 'a');
		else if (bottom > top && mid > bottom)
			ft_swap_stack(stack, 'a');
		if (top > mid && bottom > top)
			ft_swap_stack(stack, 'a');
		else if (top > bottom && bottom > mid)
			ft_rotate_stack(stack, 'a');
		else if (mid > top && top > bottom)
			ft_reverse_rotate_stack(stack, 'a');
	}
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	distance;

	if ((*a)->index == -1)
		ft_set_index(a);
	distance = ft_distance(a, ft_index_min(a));
	if (distance == 1 || distance == 2)
		while (distance)
		{
			ft_rotate_stack(a, 'a');
			distance--;
		}
	else if (distance == 3)
		ft_reverse_rotate_stack(a, 'a');
	if (!ft_is_sorted(a))
	{
		ft_push_stack(a, b, 'b');
		ft_sort_three(a);
		ft_push_stack(b, a, 'a');
	}	
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	distance;

	ft_set_index(a);
	distance = ft_distance(a, ft_index_min(a));
	if (distance == 1 || distance == 2)
		while (distance)
		{
			ft_rotate_stack(a, 'a');
			distance--;
		}
	else if (distance == 3 || distance == 4)
		while (distance != 5)
		{
			ft_reverse_rotate_stack(a, 'a');
			distance++;
		}
	if (!ft_is_sorted(a))
	{
		ft_push_stack(a, b, 'b');
		ft_sort_four(a, b);
		ft_push_stack(b, a, 'a');
	}	
}