/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:33:41 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/19 17:11:07 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_stack	*ft_get_max(t_stack **stack)
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

t_stack	*ft_get_min(t_stack **stack)
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

int	ft_get_index(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	int		index;

	temp = *stack;
	index = 0;
	while (temp != el)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

t_stack	*ft_get_min_op(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*last;
	int		count;

	temp = *stack;
	max = ft_get_max(stack);
	last = ft_bottom(temp);
	count = 0;
	while (temp)
	{
		if (((temp->n < el->n && last->n > el->n)
				|| (temp->n > el->n && last->n == max->n)
				|| (temp->n < el->n && last->n == max->n && el->n < max->n)))
			break ;
		last = temp;
		count++;
		temp = temp->next;
	}
	return (temp);
}

int	ft_count_op(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*last;
	int		count;

	temp = *stack;
	max = ft_get_min(stack);
	last = ft_bottom(temp);
	count = 0;
	while (temp)
	{
		if (((temp->n < el->n && last->n > el->n)
				|| (temp->n < el->n && last->n == max->n)
				|| (temp->n > el->n && last->n == max->n && el->n < max->n)))
			break ;
		last = temp;
		count++;
		temp = temp->next;
	}
	return (count);
}

void    ft_move_to_top(t_stack **stack, t_stack *el, char name)
{
	t_stack *temp;
	size_t     count;
	size_t	size;

	temp = *stack;
	count = ft_get_index(stack, el);
	size = ft_size(stack);
	if (count > size / 2)
		while (count++ < size)
			ft_reverse_rotate_stack(stack, name);
	else
		while (count--)
			ft_rotate_stack(stack, name);
}

void	ft_selection_sort(t_stack **a, t_stack **b)
{
	size_t	size;

	size = 0;
	while (!ft_is_sorted(a))
	{
		size++;
		ft_move_to_top(a, ft_get_min(a), 'a');
		ft_push_stack(a, b, 'b');
	}
	while (size--)
		ft_push_stack(b, a, 'a');
}

int	ft_count_to_top(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	size_t	count;
	size_t	size;
	int		op;

	temp = *stack;
	count = ft_get_index(stack, el);
	op = 0;
	size = ft_size(stack);
	if (count > size / 2)
		while (count++ < size)
			op++;
	else
		while (count--)
			op++;
	return (op);
}

t_stack	*ft_get_lowest(t_stack **a, t_stack **b)
{
	t_stack *temp;
	t_stack	*lowest;
	int		c_op;
	int		op;

	temp = *a;
	op = MAX_INT;
	lowest = temp;
	while (temp)
	{
		c_op = ft_count_to_top(a, temp) + ft_count_op(b, temp) + 1;
		if (c_op < op)
		{
			op = c_op;
			lowest = temp;
		}
		temp = temp->next;
	}
	return (lowest);	
}

void	ft_prepare(t_stack **b, int mov, char name)
{
	size_t	size;
	size_t	move;

	size = ft_size(b);
	move = (size_t) mov;
	if (move > size / 2)
		while (move++ < size)
			ft_reverse_rotate_stack(b, name);
	else
		while (move--)
			ft_rotate_stack(b, name);
}

void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el, size_t s_a)
{
	size_t	n;
	size_t		m;
	size_t		i;
	size_t	s_b;

	s_b = ft_size(b);
	n = ft_get_index(a, el);
	m = ft_count_op(b, el);
	if (n > s_a / 2 && m > s_b / 2)
	{
		i = ft_min_value(n, m);
		while (i < s_a && i < s_b)
		{
			ft_rrr(a, b);
			i++;
		}
	}
	else if (n <= s_a / 2 && m <= s_b / 2)
	{
		i = ft_min_value(n, m);
		while (i--)
			ft_rr(a, b);
	}
}

void	ft_cost_sort(t_stack **a, t_stack **b)
{
	size_t	size;
	t_stack	*el;
	int		i;

	size = ft_size(a);
	while (size > 45)
	{		
		el = ft_get_lowest(a, b);
		ft_do_both_rot(a, b, el, ft_size(a));
		ft_move_to_top(a, el, 'a');
		ft_prepare(b, ft_count_op(b, el), 'b');
		ft_push_stack(a, b, 'b');
		size = ft_size(a);
	}
	ft_move_to_top(b, ft_get_max(b), 'b');	
	ft_selection_sort(a, b);
	i = 45;
	while (i > 0 || !ft_empty(b))
	{
		if (ft_empty(b) || (i && (*b)->n < ft_bottom(*a)->n))
		{
			i--;
			ft_reverse_rotate_stack(a, 'a');
		}
		else
			ft_push_stack(b, a, 'a');
	}
	ft_move_to_top(a, ft_get_min(a), 'a');
}