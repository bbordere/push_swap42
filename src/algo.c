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

#include "push_swap.h"

int	ft_set_markup(t_stack **a, t_stack *mark_h, int mark)
{
	t_stack	*temp;
	int		count;
	int		val;

	count = 0;
	temp = *a;
	while (temp != mark_h)
		temp = temp->next;
	val = temp->n;
	while (temp)
	{
		if (temp->n > val)
		{
			if (mark)
				temp->keep_a = 1;
			count++;
			val = temp->n;
		}
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_find_mark_head(t_stack **a)
{
	t_stack	*temp;
	t_stack	*mark_head;
	int		count_mark;
	int		current_count;

	count_mark = 0;
	current_count = 0;
	temp = *a;
	mark_head = temp;
	while (temp)
	{
		current_count = ft_set_markup(a, temp, 0);
		if (current_count > count_mark)
		{
			mark_head = temp;
			count_mark = current_count;
		}
		temp = temp->next;
	}
	return (mark_head);
}

size_t	ft_total_op(t_stack **a, t_stack **b, t_stack *el)
{
	size_t	op_a;
	size_t	op_b;
	size_t	total;

	op_a = ft_get_index_a(a, el);
	op_b = ft_get_index(b, el);
	total = ft_opti_rot(a, op_a) + ft_opti_rot(b, op_b);
	if ((op_a > ft_size(a) / 2 && op_b > ft_size(b) / 2))
		total -= ft_min_value(ft_opti_rot(a, op_a), ft_opti_rot(b, op_b));
	else if (op_a <= ft_size(a) / 2 && op_b <= ft_size(b) / 2)
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

	size = ft_size(a);
	ft_set_markup(a, ft_find_mark_head(a), 1);
	while (size)
	{
		if ((*a)->keep_a == 0)
			ft_push_stack(a, b, 'b');
		else
			ft_rotate_stack(a, 'a');
		size--;
	}
	while (*b)
		ft_move_push_stacks(a, b);
	ft_move_to_top(a, ft_find_min(a), 'a');
}