/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:19:22 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/25 11:27:15 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_ss(t_stack **a, t_stack **b, int p)
{
	ft_swap_stack(a, ' ');
	ft_swap_stack(b, ' ');
	if (p)
		ft_putendl_fd("ss", 1);
}

void	ft_rr(t_stack **a, t_stack **b, int p)
{
	ft_rotate_stack(a, ' ');
	ft_rotate_stack(b, ' ');
	if (p)
		ft_putendl_fd("rr", 1);
}

void	ft_rrr(t_stack **a, t_stack **b, int p)
{
	ft_reverse_rotate_stack(a, ' ');
	ft_reverse_rotate_stack(b, ' ');
	if (p)
		ft_putendl_fd("rrr", 1);
}

void	ft_fill_stack(t_stack **a, int n, int ac, char **av)
{
	t_stack	*new;

	new = ft_stacknew(n);
	if (!new)
	{
		ft_free_stack(a);
		if (ac == 2)
			ft_free(av);
		exit(1);
	}
	ft_push(a, new);
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
		ft_fill_stack(a, ft_atoi(av[--args]), ac, av);
	if (ac == 2)
		ft_free(av);
	ft_set_index(a);
}
