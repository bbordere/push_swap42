/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 14:46:40 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/01 14:46:40 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_insert(t_stack **stack, t_stack *x)
{
    t_stack *temp;

    if (isEmpty(*stack) || x -> n > top(*stack))
    {
        ft_push(stack, x);
        return ;
    }
    temp = ft_pop(stack);
    ft_sort_insert(stack, x);
    ft_push(stack, temp);
}
