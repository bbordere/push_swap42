/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:35:59 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/24 14:55:22 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_find_min(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*min;

	temp = *stack;
	min = temp;
	while (temp)
	{
		if (temp->n < min->n)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*ft_find_max(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*max;

	temp = *stack;
	max = temp;
	while (temp)
	{
		if (temp->n > max->n)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_stack	*ft_get_i_el(t_stack **stack, int i)
{
	t_stack	*temp;

	temp = *stack;
	while (i--)
		temp = temp->next;
	return (temp);
}

void	ft_move_to_top(t_stack **stack, t_stack *el, char name)
{
	t_stack	*temp;
	size_t	count;
	size_t	size;
	size_t	i;

	temp = *stack;
	count = ft_get_index(stack, el);
	size = ft_size(stack);
	i = ft_opti_rot(stack, count);
	if (count > (size / 2))
		while (i--)
			ft_reverse_rotate_stack(stack, name);
	else
		while (i--)
			ft_rotate_stack(stack, name);
}