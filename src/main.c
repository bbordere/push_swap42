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

#include "push_swap.h"

#include <time.h>
#include <stdio.h>

void ft_free(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

int	ft_count_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	ft_free_stack(t_stack **stack)
{
	while (!ft_empty(stack) && (*stack)->next)
		free(ft_pop_bottom(stack));
	free((*stack));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		start;

	a = NULL;
	b = NULL;
	start = 1;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		ac = ft_count_av(av);
		start = 0;
		if (!*av)
			exit(0);
	}	
	ft_check_args(ac, av, start);
	while (ac > start)
		ft_push(&a, ft_stacknew(ft_atoi(av[--ac]), 'a'));
	//ft_sort_stack(&a, &b);
	ft_radix_lsd(&a, &b);
	ft_free(av);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
