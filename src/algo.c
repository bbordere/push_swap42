/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:16:24 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/24 14:42:48 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_find_median(t_stack **stack)
{
	t_stack	*temp;
	size_t	med;

	temp = *stack;
	med = ft_size(stack) / 2;
	while (temp && (size_t)temp->index != med)
		temp = temp->next;
	return (temp);
}

void	ft_set_markup(t_stack **a)
{
	t_stack	*med;
	t_stack	*temp;

	med = ft_find_median(a);
	temp = *a;
	while (temp)
	{
		if (temp->n <= med->n)
			temp->keep_a = 1;
		temp = temp->next;
	}
}

size_t	ft_total_op(t_stack **a, t_stack **b, t_stack *el)
{
	size_t	op_a;
	size_t	op_b;
	size_t	total;
	size_t	size_a;
	size_t	size_b;

	size_a = ft_size(a);
	size_b = ft_size(b);
	op_a = ft_get_index_a(a, el);
	op_b = ft_get_index(b, el);
	total = ft_opti_rot(a, op_a) + ft_opti_rot(b, op_b);
	if ((op_a > size_a / 2 && op_b > size_b / 2))
		total -= ft_min_value(ft_opti_rot(a, op_a), ft_opti_rot(b, op_b));
	else if (op_a <= size_a / 2 && op_b <= size_b / 2)
		total -= ft_min_value(ft_opti_rot(a, op_a), ft_opti_rot(b, op_b));
	return (total);
}

t_stack	*ft_select(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*element;
	size_t	op;
	size_t	cop;

	temp = *b;
	op = MAX_INT;
	element = temp;
	while (temp)
	{
		cop = ft_total_op(a, b, temp);
		if (cop < op)
		{
			op = cop;
			element = temp;
		}
		temp = temp->next;
	}
	return (element);
}

void	ft_mark_sort(t_stack **a, t_stack**b)
{
	size_t	size;

	ft_set_markup(a);
	size = ft_size(a);
	while (size--)
	{
		if ((*a)->keep_a == 0)
			ft_push_stack(a, b, 'b');
		else
			ft_rotate_stack(a, 'a');
	}
	while ((*a)->next)
		ft_push_stack(a, b, 'b');
	while (*b)
		ft_move_push_stacks(a, b);
	ft_move_to_top(a, ft_find_min(a), 'a');
}
