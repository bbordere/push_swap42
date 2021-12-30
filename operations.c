/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:39:31 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 16:17:06 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	ft_swap_stack(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	ft_swap_stack(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	ft_push_stack(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	ft_push_stack(a, b);
	write(1, "pb\n", 3);
}
