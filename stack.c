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

t_stack	*ft_stacknew(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> n = n;
	new -> next = NULL;
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
	return (temp);
}

void	ft_push_stack(t_stack **src, t_stack **dest)
{
	if (!*src)
		return ;
	ft_push(dest, ft_pop(src));
}

void	ft_swap_stack(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	if (!*stack || !((*stack)->next))
		return ;
	top = ft_pop(stack);
	bottom = ft_pop(stack);
	ft_push(stack, top);
	ft_push(stack, bottom);
}

#include <stdio.h>

void	print(t_stack **stack)
{
	t_stack *temp = *stack;
	while (temp)
	{
		printf("%d -> ", temp->n);
		temp = temp->next;
	}
	printf("NULL\n");
}



