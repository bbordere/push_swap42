/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:13:48 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/14 10:57:02 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_median(t_stack **stack)
{
	t_stack	*temp;
	int		med;

	temp = *stack;
	med = ft_size(stack) / 2;
	while (temp->index != med)
		temp = temp->next;
	return (temp->n);
}

void	ft_quicksort(t_stack **a, t_stack **b, int n)
{
	int		i;
	int		count;
	t_stack	*temp;
	int		med;

	i = 0;
	count = 0;
	temp = *a;
	med = ft_find_median(a);
	if (n == 1)
		return ;
	while (i++ <= n)
	{
		if (temp->index > med)
		{
			ft_push_stack(a, b, 'b');
			count++;
		}
		ft_rotate_stack(a, 'a');
	}
	i = n - count;
	while (i--)
		ft_reverse_rotate_stack(a, 'a');
	i = count;
	while (i--)
		ft_push_stack(b, a, 'a');
	ft_quicksort(a, b, count);
	i = n - count;
	while (i--)
		ft_rotate_stack(a, 'a');
	ft_quicksort(a, b, n - count);
	while (count--)
		ft_reverse_rotate_stack(a, 'a');
}
