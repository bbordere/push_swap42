/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:39:31 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 16:17:06 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap_stack(a, 'a');
	ft_swap_stack(b, 'b');
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate_stack(a, 'a');
	ft_rotate_stack(b, 'b');
}

size_t	ft_size(t_stack **stack)
{
	size_t	i;

	i = 0;
	while (!ft_empty(stack))
	{
		i++;
		*stack = (*stack)->next;
	}
	return (i);
}
