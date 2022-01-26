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

#include "includes/push_swap.h"

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
		new -> prev = p;
	}
}

t_stack	*ft_pop_bottom(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*temp;
	t_stack	*poped;

	if (!*stack)
		return (NULL);
	bottom = ft_bottom(*stack);
	temp = *stack;
	while ((*stack) && (*stack)->next != bottom)
		*stack = (*stack)->next;
	poped = ft_pop(&(*stack)->next);
	*stack = temp;
	return (poped);
}

void	ft_rotate_stack(t_stack **stack, char name)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = ft_pop(stack);
	ft_add_bottom(stack, tmp);
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate_stack(t_stack **stack, char name)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	tmp = ft_pop_bottom(stack);
	ft_push(stack, tmp);
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
}
