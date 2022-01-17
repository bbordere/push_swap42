/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:15:59 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/15 23:15:59 by bbordere         ###   ########.fr       */
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

int	ft_count_to_top_2(t_stack **stack, t_stack *el)
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

void	ft_reset_mark(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->keep_a = 0;
		temp = temp->next;
	}	
}

int		ft_count_mark(t_stack **stack, t_stack *mark_head)
{
	t_stack	*temp;
	t_stack	*temp_head;
	int		count;

	temp = *stack;
	count = 0;
	temp_head = mark_head;
	while (temp)
	{
		if (temp->index == temp_head->index + 1)
		{
			temp->keep_a = 1;
			temp_head = temp;
			count++;
		}
		temp = temp->next;	
	}
	return (count);
}

t_stack	*ft_find_best_markup(t_stack **stack)
{
	t_stack *mark_head;
	t_stack *temp;
	int		count;

	temp = *stack;
	count = 0;
	mark_head = temp;
	while (temp)
	{	
		if (ft_count_mark(stack, temp) > count)
		{
			count = ft_count_mark(stack, temp);
			mark_head = temp;
			mark_head->keep_a = 1;
		}
		ft_reset_mark(stack);
		temp = temp -> next;
	}
	return (mark_head);
}

/*
int	ft_set_markup(t_stack **stack)
{
	t_stack	*mark_head;
	t_stack	*temp;
	int count;
	int		index;

	mark_head = ft_find_best_markup(stack);
	count = 0;
	temp = *stack;
	index = mark_head->index;
	while (temp != mark_head)
	{
		if (temp->index == index + 1)
		{
			temp->keep_a = 1;
			count++;
			index++;
		}
		else
			temp->keep_a = 0;
		temp = temp->next;
	}
	return (count);
}
*/

int ft_set_markup(t_stack **stack)
{
	t_stack	*mark_head;
	t_stack	*temp;
	int count;
	int		index;

	mark_head = ft_find_best_markup(stack);
	count = 0;
	temp = *stack;
	index = mark_head->index;
	while(temp != mark_head)
	{
		if (temp -> index > index)
		{
			count++;
			index = temp -> index;
			temp -> keep_a = 1;
		}
		else
			temp -> keep_a = 0;
		temp = temp -> next;
	}
	return (count);
}

int	ft_count_to_top(t_stack **stack, t_stack *el)
{
	t_stack	*temp;
	size_t	count;
	size_t	size;
	int		op;

	temp = *stack;
	count = ft_count_to_top_2(stack, el);
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
				|| (temp->n < el->n && last->n == max->n && el->n > max->n)))
			break ;
		last = temp;
		temp = temp->next;
	}
	return (temp);
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
		count = ft_count_a(a, temp);
		if (count > ft_size(a) / 2)
			count = ft_size(a) - count + 1;
		cop = count + ft_count_to_top(b, temp);
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
	count = ft_count_to_top_2(stack, el);
	size = ft_size(stack);
	if (count > size / 2)
		while (count++ < size)
			ft_reverse_rotate_stack(stack, name);
	else
		while (count--)
			ft_rotate_stack(stack, name);
}

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el, size_t s_a)
{
	size_t	n;
	size_t		m;
	size_t		i;
	size_t	s_b;

	s_b = ft_size(b);
	n = ft_count_a(a, el);
	m = ft_count_to_top_2(b, el);
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

void	ft_mark_sort(t_stack **a, t_stack **b)
{
	int count;
	int count2;

	while (ft_not_in_a(a))
	{
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
		if ((*a)->keep_a == 0)
			ft_push_stack(a, b, 'b');
		else
			ft_rotate_stack(a, 'a');
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