/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:16:24 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/23 22:05:38 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_find_min(t_stack **stack)
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

static t_stack	*ft_find_max(t_stack **stack)
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

int	ft_get_index(t_stack **stack, t_stack *el)
{
	t_stack *temp;
	int     count;

	temp = *stack;
	count = 0;
	while (temp && temp != el)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int ft_set_markup(t_stack **a, t_stack *mark_h, int mark)
{
	t_stack *temp;
	int     count;
	int     val;

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

t_stack *ft_find_mark_head(t_stack **a)
{
	t_stack *temp;
	t_stack *mark_head;
	int     count_mark;
	int     current_count;

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

int	ft_get_index_a(t_stack **a, t_stack *el)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*prev;
	int		count;

	temp = *a;
	max = ft_find_max(a);
	prev = ft_bottom(*a);
	count = 0;
	while (temp)
	{
		if ((temp->n > el->n && (prev->n < el->n || prev->n == max->n))
			|| (temp->n < el->n && el->n > max->n && prev->n == max->n))
			return (count);
		prev = temp;
		count++;
		temp = temp->next;
	}
	return (count);
}

size_t ft_optimize_rot(t_stack **stack, size_t index)
{
	if (index > (ft_size(stack) / 2))
		return (ft_size(stack) - index);
	return (index);
}

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_stack	*ft_get_i_el(t_stack **stack, int i)
{
	t_stack *temp;

	temp = *stack;
	while (i--)
		temp = temp->next;
	return (temp);	
}

size_t ft_total_op(t_stack **a, t_stack **b, t_stack *el)
{
	size_t op_a;
	size_t op_b;
	size_t total;

	op_a = ft_get_index_a(a, el);
	op_b = ft_get_index(b, el);
	total = ft_optimize_rot(a, op_a) + ft_optimize_rot(b, op_b);
	if ((op_a > ft_size(a) / 2 && op_b > ft_size(b) / 2))
		total -= ft_min_value(ft_optimize_rot(a, op_a), ft_optimize_rot(b, op_b));
	else if (op_a <= ft_size(a) / 2 && op_b <= ft_size(b) / 2)
		total -= ft_min_value(ft_optimize_rot(a, op_a), ft_optimize_rot(b, op_b));
	return (total);
}

t_stack	*ft_select(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*element;
	size_t		op;
	size_t		cop;

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

void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el)
{
	size_t	op_a;
	size_t	op_b;
	size_t	i;

	op_a = ft_get_index_a(a, el);
	op_b = ft_get_index(b, el);
	i = ft_min_value(ft_optimize_rot(a, op_a), ft_optimize_rot(b, op_b));
	if (op_a > (ft_size(a) / 2) && op_b > (ft_size(b) / 2))
		while (i--)
			ft_rrr(a, b);
	else if (op_a <= (ft_size(a) / 2) && op_b <= (ft_size(b) / 2))		
		while (i--)
			ft_rr(a, b);
}

void    ft_move_to_top(t_stack **stack, t_stack *el, char name)
{
	t_stack *temp;
	size_t	count;
	size_t	size;
	size_t	i;

	temp = *stack;
	count = ft_get_index(stack, el);
	size = ft_size(stack);
	i = ft_optimize_rot(stack, count);
	if (count > (size / 2))
		while (i--)
			ft_reverse_rotate_stack(stack, name);
	else
		while (i--)
			ft_rotate_stack(stack, name);
}

void	ft_move_push_stacks(t_stack **a, t_stack **b)
{
	t_stack	*el;

	el = ft_select(a, b);
	ft_do_both_rot(a, b, el);
	ft_move_to_top(a, ft_get_i_el(a, ft_get_index_a(a, el)), 'a');
	ft_move_to_top(b, el, 'b');
	ft_push_stack(b, a, 'a');
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