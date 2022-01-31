/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:19:16 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/06 16:54:33 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
/*
#include <stdio.h>

void	reverse_print(t_stack **stack)
{
	t_stack *temp = *stack;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		printf("%d <- ", temp->n);
		temp = temp->prev;
	}
	printf("NULL\n");
}

void	print(t_stack **stack)
{
	t_stack *temp = *stack;
	while (temp)
	{
		printf("%d -> ", temp->n);
		temp = temp->next;
	}
	printf("NULL\n");
}
*/

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_init_stacks(&a, av, ac);
	if (!ft_is_sorted(&a))
		ft_do_sort(&a, &b, ft_size(&a));
	ft_free_stack(&a);
	ft_free_stack(&b);
}
