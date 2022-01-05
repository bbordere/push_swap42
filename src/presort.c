/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:30:13 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/05 16:51:24 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_min(t_stack **a)
{
	t_stack	*temp;
	t_stack	*s_min;
	int		min;

	temp = *a;
	s_min = NULL;
	min = 0;
	while (temp)
	{
		if ((temp->index) == -1 && (!min || temp -> n < s_min -> n))
		{
			min = 1;
			s_min = temp;
		}
		temp = temp->next;
	}
	return (s_min);
}

void	ft_set_index(t_stack **stack)
{
	size_t	i;
	size_t	size;
	t_stack	*temp;

	i = -1;
	temp = (*stack);
	size = ft_size(&temp);
	while (size > ++i)
		ft_min(&temp)->index = i;
}
