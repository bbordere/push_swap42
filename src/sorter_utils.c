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

#include "includes/push_swap.h"

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

int	ft_get_index(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	int		count;

	temp = *stack;
	count = 0;
	while (temp && temp != el)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

size_t	ft_opti_rot(t_stack **stack, size_t index)
{
	if (index > (ft_size(stack) / 2))
		return (ft_size(stack) - index);
	return (index);
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
	else
		ft_mark_sort(a, b);
}
