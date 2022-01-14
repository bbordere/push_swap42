/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_opti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:09:31 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/14 13:05:01 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_top_chunk_number(t_stack **stack, int min, int max)
{
	t_stack	*temp;
	size_t	size;
	size_t	move;

	move = 0;
	size = ft_size(stack) / 2;
	temp = *stack;
	while (temp && move < size)
	{
		if (temp->index >= min && temp->index <= max)
			return (move);
		move++;
		temp = temp->next;
	}
	return (move);
}

size_t	ft_bottom_chunk_number(t_stack **stack, int min, int max)
{
	t_stack	*temp;
	size_t	size;
	size_t	move;

	move = 1;
	size = ft_size(stack) / 2;
	temp = ft_bottom(*stack);
	while (temp && move < size)
	{
		if (temp->index >= min && temp->index <= max)
			return (move);
		move++;
		temp = temp->prev;
	}
	return (move);
}

void	ft_sort(t_stack **stack)
{
	int	min;
	int	max;
	int	n;

	max = ft_size(stack) / 5;
	min = 0;
	if (ft_top_chunk_number(stack, min, max) > ft_bottom_chunk_number(stack, min, max))
	{
		n = ft_top_chunk_number(stack, min, max);
		while (n--)
			ft_rotate_stack(stack, 'a');		
	}
	else
	{
		n = ft_top_chunk_number(stack, min, max);
		while (n--)
			ft_reverse_rotate_stack(stack, 'a');
	}
}