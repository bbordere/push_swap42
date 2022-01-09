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
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	int				n;
	int				index;
	char			name;
}	t_stack;

t_stack	*ft_stacknew(int n, char name);
t_stack	*ft_min(t_stack **a);
void	ft_set_index(t_stack **stack);
void	ft_push_stack(t_stack **src, t_stack **dest, char dst);
void	ft_swap_stack(t_stack **stack, char name);
void	ft_rotate_stack(t_stack **stack, char name);
void	ft_push(t_stack **stack, t_stack *new);
void	ft_reverse_rotate_stack(t_stack **stack, char name);
t_stack	*ft_pop_bottom(t_stack **stack);
t_stack	*ft_pop(t_stack **stack);
int		ft_empty(t_stack **start);
void	print(t_stack **stack);
size_t	ft_size(t_stack **stack);
int		ft_is_sorted(t_stack **stack);
size_t	ft_digits(t_stack **stack);
void	ft_radix_lsd(t_stack **a, t_stack **b);
void	ft_set_index(t_stack **stack);
void	ft_sort_stack(t_stack **a, t_stack **b);
void	ft_check_args(int ac, char **av, int start);
void	ft_sort_three(t_stack **stack);
void	ft_sort_two(t_stack **stack);
void	ft_free_stack(t_stack **stack);
void	ft_free(char **av);
#endif