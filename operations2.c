/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:58:04 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 16:20:50 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_bottom(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack && stack -> next)
		stack = stack -> next;
	return (stack);
}

void	ft_add_bottom(t_stack **stack, t_stack *new)
{	
	t_stack	*p;

	if (!*stack)
		*stack = new;
	else
	{
		p = ft_bottom(*stack);
		p -> next = new;
	}
}

void	ft_rotate_stack(t_stack **stack, char name)
{
	t_stack	*tmp;

	tmp = ft_pop(stack);
	ft_add_bottom(stack, tmp);
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
}
