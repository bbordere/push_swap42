/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:19:16 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/05 17:11:31 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <time.h>
#include <stdio.h>

void	ft_free_stack(t_stack **stack)
{
	while (!ft_empty(stack) && (*stack)->next)
		free(ft_pop_bottom(stack));
	free((*stack));
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_check_args(ac, av);
	while (ac > 1)
		ft_push(&a, ft_stacknew(ft_atoi(av[--ac]), 'a'));
	ft_radix_lsd(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
