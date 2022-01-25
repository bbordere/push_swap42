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

size_t	ft_size(t_stack **stack)
{
	size_t	i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack);
	while (temp && temp -> next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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