/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:40:42 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 15:51:19 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int n, char name)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> n = n;
	new -> next = NULL;
	new -> name = name;
	new -> index = -1;
	return (new);
}

void	ft_push(t_stack **stack, t_stack *new)
{
	if (*stack)
		new -> next = *stack;
	*stack = new;
}

t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return (NULL);
	temp = *stack;
	*stack = temp -> next;
	temp -> next = NULL;
	return (temp);
}

void	ft_push_stack(t_stack **src, t_stack **dest, char name)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = ft_pop(src);
	temp -> next = NULL;
	ft_push(dest, temp);
	if (name == 'a')
		write(1, "pa\n", 3);
	else if (name == 'b')
		write(1, "pb\n", 3);
}

void	ft_swap_stack(t_stack **stack, char dst)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!*stack || !((*stack)->next))
		return ;
	top = ft_pop(stack);
	bottom = ft_pop(stack);
	ft_push(stack, top);
	ft_push(stack, bottom);
	if (dst == 'a')
		write(1, "sa\n", 3);
	else if (dst == 'b')
		write(1, "sb\n", 3);
}
