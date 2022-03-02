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
