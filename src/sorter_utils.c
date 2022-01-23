/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:29:51 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/11 15:29:51 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index_min(t_stack **stack)
{
	int		index;
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

int	ft_distance(t_stack **stack, int index)
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

void	ft_do_sort(t_stack **a, t_stack **b, size_t size)
{
	if (size == 2)
		ft_sort_two(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
	/*
	else if (size >= 6 && size <= 36)
		ft_sort_stack(a, b);
	*/
	else
		ft_mark_sort(a, b);
}
