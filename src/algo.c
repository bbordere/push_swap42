/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastien <bastien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:11:32 by bastien           #+#    #+#             */
/*   Updated: 2022/01/20 20:26:02 by bastien          ###   ########.fr       */
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

int	ft_get_index(t_stack **stack, t_stack *el)
{
	t_stack *temp;
	int     count;
	size_t	size;

	temp = *stack;
	count = 0;
	size = ft_size(stack);
	while (temp != el)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_not_in_a(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->keep_a == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
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

void ft_best_mark_head(t_stack **a)
{
    t_stack *head;

    head = ft_find_mark_head(a);
    ft_set_markup(a, head, 1);
}

// int	ft_set_markup(t_stack **stack)
// {
// 	t_stack	*mark_head;
// 	t_stack	*temp;
// 	int count;
// 	int		index;

// 	mark_head = ft_find_best_markup(stack);
// 	count = 0;
// 	temp = *stack;
// 	index = mark_head->index;
// 	while (temp != mark_head)
// 	{
// 		if (temp->index == index + 1)
// 		{
// 			temp->keep_a = 1;
// 			count++;
// 			index++;
// 		}
// 		else
// 			temp->keep_a = 0;
// 		temp = temp->next;
// 	}
// 	return (count);
// }

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

int	ft_count_a(t_stack	**a, t_stack *el)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*last;
	int		count;

	temp = *a;
	max = ft_find_max(a);
	last = ft_bottom(temp);
	count = 0;
	while (temp)
	{
		if (((temp->n > el->n && last->n < el->n)
				|| (temp->n > el->n && last->n == max->n)
				|| (temp->n < el->n && last->n == max->n && el->n > max->n)))
			break ;
		last = temp;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_stack	*ft_best_el_a(t_stack **a, t_stack *el)
{
	t_stack	*temp;
	t_stack	*max;
	t_stack	*last;

	temp = *a;
	max = ft_find_max(a);
	last = ft_bottom(*a);
	while (temp)
	{
		if (((temp->n > el->n && last->n < el->n)
				|| (temp->n > el->n && last->n == max->n)
				|| (temp->n < el->n && (last->n == max->n && el->n > max->n))))
			break ;
		last = temp;
		temp = temp->next;
	}
	return (temp);
}

int ft_optimize_rot(t_stack **stack, int rot)
{
    if (rot > ft_size(stack) / 2)
        return (ft_size(stack) - rot + 1);
    return (rot);
}

int ft_total_op(t_stack **a, t_stack **b, t_stack *el)
{
    int op_a;
    int op_b;
    int total;

    op_a = ft_count_a(a, el);
    op_b = ft_get_index(b, el);
    if (op_a > ft_size(a) / 2 && op_b > ft_size(b) / 2)
        total = ft_max_value(op_a, op_b);
	else if (op_a <= ft_size(a) / 2 && op_b <= ft_size(b) / 2)
        total = ft_max_value(op_a, op_b);
    else
        total = ft_optimize_rot(a, op_a) + ft_optimize_rot(b, op_b);
    return (total + 1);
}

t_stack	*ft_select(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*element;
	int		op;
	int		cop;
	size_t		count;

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



void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el, size_t s_a)
{
	size_t	n;
	size_t		m;
	size_t		i;
	size_t	s_b;

	s_b = ft_size(b);
	n = ft_count_a(a, el);
	m = ft_get_index(b, el);
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

void	ft_prepare_stacks(t_stack **a, t_stack **b)
{
	t_stack	*el;
	int		size;

	size = ft_size(a);
	el = ft_select(a, b);
	ft_do_both_rot(a, b, el, size);
	ft_move_to_top(b, el, 'b');
	ft_move_to_top(a, ft_best_el_a(a, el), 'a');
	/*
	n = ft_count_a(a, el);
	if (n > size / 2)
		while (n++ < size)
			ft_reverse_rotate_stack(a, 'a');
	else
		while (n--)
			ft_rotate_stack(a, 'a');
	*/
	ft_push_stack(b, a, 'a');
}

t_stack	*ft_best_a_to_b(t_stack **a)
{
	t_stack	*temp;
	t_stack	*best;
	int		count;
	int		op;

	temp = *a;
	best = temp;
	op = MAX_INT;
	while (temp)
	{	
		count = ft_count_to_top(a, temp);
		if (temp->keep_a == 0)
		{
			if (count < op)
			{
				op = count;
				best = temp;
			}
		}
		temp = temp->next;
	}
	return (best);
}

void	ft_mark_sort(t_stack **a, t_stack **b)
{
	// int count;
	// int count2;
    size_t  size;

    size = ft_size(a);
	ft_best_mark_head(a);
	while (size)
	{
		
		/*
		count = ft_set_markup(a);
		ft_swap_stack(a,' ');
		ft_reset_mark(a);
		count2 = ft_set_markup(a);
		if (count2 < count)
		{
			ft_swap_stack(a,' ');
			ft_set_markup(a);
		}
		else
			ft_swap_stack(a,' ');
		ft_move_to_top(a, ft_best_a_to_b(a), 'a');
		ft_push_stack(a, b, 'b');
		*/
		if ((*a)->keep_a == 0)
			ft_push_stack(a, b, 'b');
		else
			ft_rotate_stack(a, 'a');
        size--;
	}
	while (!ft_empty(b))
		ft_prepare_stacks(a, b);
	ft_move_to_top(a, ft_find_min(a), 'a');
/*
	while (ft_bottom(*a) != ft_find_max(a))
	{
		ft_reverse_rotate_stack(a, 'a');
		ft_swap_stack(a,'a');
	}
	*/
}