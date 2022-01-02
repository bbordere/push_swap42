/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:49:11 by bbordere          #+#    #+#             */
/*   Updated: 2021/12/30 15:50:41 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				n;
	char			name;
}	t_stack;

t_stack	*ft_stacknew(int n, char name);
void	ft_push_stack(t_stack **src, t_stack **dest, char dst);
void	ft_swap_stack(t_stack **stack, char name);
void	ft_rotate_stack(t_stack **stack, char name);
void	ft_push(t_stack **stack, t_stack *new);
t_stack	*ft_pop(t_stack **stack);
void	print(t_stack **stack);

#endif