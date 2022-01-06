/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:59:19 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/06 14:04:53 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	if (!ft_is_sorted(stack))
		ft_rotate_stack(stack, 'a');
}

void	ft_sort_three(t_stack **stack)
{
	if (!ft_is_sorted(stack))
	{
		
	}
}
