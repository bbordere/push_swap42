/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:58:04 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 16:20:50 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_rotate_stack(t_stack **stack)
{
	t_stack	*rota;
	t_stack	*tmp;

	tmp = NULL;
	rota = ft_stacknew(ft_pop(stack)->n);
	/*while (*stack)
	{
		ft_push_stack(stack, &tmp);
		(*stack) = (*stack)->next;
	}
	while (*tmp)
	{
		ft_push_stack(tmp, rota);
		(*tmp) = (*tmp)->next;
	}
	free(stack);
	free(tmp);*/
	return (rota);
}

int main(int argc, char const *argv[])
{
	t_stack *a;
	ft_push(&a, ft_stacknew(5));
	ft_push(&a, ft_stacknew(6));
	ft_push(&a, ft_stacknew(7));
	print(&a);
	ft_rotate_stack(&a);
	print(&a);
	return 0;
}