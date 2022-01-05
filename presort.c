/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:30:13 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/04 16:40:24 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_min(t_stack **a)
{
	t_stack	*temp;
	t_stack	*s_min;
	int		min;

	temp = *a;
	s_min = NULL;
	min = 0;
	if (temp)
	{
		while (temp)
		{
			if ((temp->index) == -1 && (!min || temp -> n < s_min -> n))
			{
				min = 1;
				s_min = temp;
			}
			temp = temp->next;
		}
	}
	return (s_min);
}

void	ft_set_index(t_stack **stack)
{
	int		i;
	size_t	size;
	t_stack	*temp;
	t_stack	*el;

	i = -1;
	temp = (*stack);
	size = ft_size(&temp);
	while (size > ++i)
		ft_min(&temp)->index = i;
}

#include <time.h>
int main()
{
	t_stack *a;
	a = NULL;
	t_stack *b;
	b = NULL;

	for (int i = 0; i != 500; i++)
	{		
		srandom(time(NULL));
		int rd = random() / 1000000;
		ft_push(&a, ft_stacknew(rd, 'a'));
	}
	/*
	ft_push(&a, ft_stacknew(-5, 'a'));
	ft_push(&a, ft_stacknew(6, 'a'));
	ft_push(&a, ft_stacknew(-8, 'a'));
	ft_push(&a, ft_stacknew(0, 'a'));
	ft_push(&a, ft_stacknew(-10, 'a'));
	ft_push(&a, ft_stacknew(-15, 'a'));
	ft_push(&a, ft_stacknew(-156, 'a'));
	ft_push(&a, ft_stacknew(-874, 'a'));
	ft_push(&a, ft_stacknew(-4, 'a'));
	ft_push(&a, ft_stacknew(-987, 'a'));
	ft_push(&a, ft_stacknew(-6541, 'a'));
	ft_push(&a, ft_stacknew(-8416, 'a'));
	ft_push(&a, ft_stacknew(96, 'a'));
	ft_push(&a, ft_stacknew(451, 'a'));
	ft_push(&a, ft_stacknew(652, 'a'));
	ft_push(&a, ft_stacknew(785, 'a'));
	ft_push(&a, ft_stacknew(12, 'a'));
	ft_push(&a, ft_stacknew(-7, 'a'));
	//ft_sort_stack(&a, &b);
	*/
	ft_radix_lsd(&a, &b);
	
	while (!ft_empty(&a) && a->next)
		free(ft_pop_bottom(&a));
	
	free(a);
	free(b);
	
	// 1957 1714 1681 846 1804
	//print(&a);
}
