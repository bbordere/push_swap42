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

void	ft_free(char **av)
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

void	ft_init_stacks(t_stack **a, char **av, int ac)
{
	int	start;
	int	args;

	start = 1;
	args = ac;
	if (args == 2)
	{
		av = ft_split(av[1], ' ');
		args = ft_count_av(av);
		start = 0;
		if (!*av)
		{
			ft_free(av);
			exit(1);
		}
	}
	ft_check_args(ac, av, start);
	while (args > start)
		ft_push(a, ft_stacknew(ft_atoi(av[--args]), 'a'));
	if (ac == 2)
		ft_free(av);
	ft_set_index(a);
}

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
		printf("%d -> ", temp->index);
		temp = temp->next;
	}
	printf("NULL\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_init_stacks(&a, av, ac);
	ft_sort(&a);
	/*
	if (!ft_is_sorted(&a))
		ft_do_sort(&a, &b, ft_size(&a));
	*/
	// print(&a);
	// reverse_print(&a);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
