/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:40:36 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/25 11:22:39 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el)
{
	size_t	op_a;
	size_t	op_b;
	size_t	i;
	size_t	size_a;
	size_t	size_b;

	size_a = ft_size(a);
	size_b = ft_size(b);
	op_a = ft_get_index_a(a, el);
	op_b = ft_get_index(b, el);
	i = ft_min_value(ft_opti_rot(a, op_a), ft_opti_rot(b, op_b));
	if (op_a > (size_a / 2) && op_b > (size_b / 2))
		while (i--)
			ft_rrr(a, b, 1);
	else if (op_a <= (size_a / 2) && op_b <= (size_b / 2))
		while (i--)
			ft_rr(a, b, 1);
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
