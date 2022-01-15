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

t_stack	*ft_find_mark_head(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (temp->index != 0)
		temp = temp->next;
	temp->keep_a = 1;
	return (temp);
}

void	ft_set_markup(t_stack **stack)
{
	t_stack *mark_head;
	t_stack *temp;

	temp = *stack;
	mark_head = ft_find_mark_head(stack);
	while (temp)
	{
		if (temp->index == mark_head->index + 1)
		{
			temp->keep_a = 1;
			mark_head = temp;
		}
		temp = temp->next;
	}
}

int	ft_count_to_top(t_stack **stack, t_stack *el)
{
	t_stack *temp;
	int     count;
	size_t	size;
	int		op;

	temp = *stack;
	count = 0;
	op = 0;
	size = ft_size(stack);
	while (temp != el)
	{
		count++;
		temp = temp->next;
	}
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
				break;
		last = temp;
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_select(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*element;
	int		op;
	int		cop;

	temp = *b;
	op = MAX_INT;
	element = temp;
	while (temp)
	{
		cop = ft_count_a(a, temp) + ft_count_to_top(b, temp);
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
	if (count > size / 2)
		while (count++ < size)
			ft_reverse_rotate_stack(stack, name);
	else
		while (count--)
			ft_rotate_stack(stack, name);
}


void	ft_prepare_stacks(t_stack **a, t_stack **b)
{
	t_stack	*el;
	int		n;
	int		size;

	size = ft_size(a);
	el = ft_select(a, b);
	ft_move_to_top(b, el, 'b');
	n = ft_count_a(a, el);
	if (n > size / 2)
		while (n++ < size)
			ft_reverse_rotate_stack(a, 'a');
	else
		while (n--)
			ft_rotate_stack(a, 'a');
	ft_push_stack(b, a, 'a');
}


void	ft_mark_sort(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*el;
	int		n;

	ft_set_markup(a);
	while (ft_not_in_a(a))
	{
		temp = *a;
		if (temp->keep_a == 0)
			ft_push_stack(a, b, 'b');
		else
			ft_rotate_stack(a, 'a');
	}
	while (!ft_empty(b))
		ft_prepare_stacks(a, b);
	ft_move_to_top(a, ft_find_min(a), 'a');
	while (ft_bottom(*a) != ft_find_max(a))
	{
		ft_reverse_rotate_stack(a, 'a');
		ft_swap_stack(a,'a');
	}
}