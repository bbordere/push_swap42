/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:30:13 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/04 16:28:27 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_digits(t_stack **stack)
{
	int		max;
	t_stack	*temp;
	size_t	digits;

	temp = *stack;
	max = temp->n;
	while (temp)
	{
		if (temp->n > max)
			max = temp->n;
		temp = temp->next;
	}
	digits = 0;
	while (max != 0)
	{
		max = max >> 1;
		digits++;
	}
	return (digits);
}

void	ft_radix_lsd(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	size_t	size;
	size_t	bit;
	size_t	max;

	bit = 0;
	max = ft_digits(a);
	ft_set_index(a);
	while (bit < max)
	{
		size = ft_size(a);
		while (size--)
		{
			tmp = (*a);
			if (((((tmp->index) >> bit) & 1)))
				ft_rotate_stack(a, 'a');
			else
				ft_push_stack(a, b, 'b');
		}
		while (ft_size(b))
			ft_push_stack(b, a, 'a');
		bit++;
	}
}
