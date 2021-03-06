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
# include "../../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				n;
	int				index;
	int				keep_a;
}	t_stack;

t_stack	*ft_stacknew(int n);
t_stack	*ft_min(t_stack **a);
t_stack	*ft_pop(t_stack **stack);
t_stack	*ft_bottom(t_stack *stack);
t_stack	*ft_find_min(t_stack **stack);
t_stack	*ft_find_max(t_stack **stack);
t_stack	*ft_pop_bottom(t_stack **stack);
t_stack	*ft_find_median(t_stack **stack);
t_stack	*ft_select(t_stack **a, t_stack **b);
t_stack	*ft_get_i_el(t_stack **stack, int i);

void	ft_free(char **av);
void	ft_error(int ac, char **av);
void	ft_sort_two(t_stack **stack);
void	ft_set_index(t_stack **stack);
void	ft_set_index(t_stack **stack);
void	ft_sort_three(t_stack **stack);
void	ft_free_stack(t_stack **stack);
void	ft_free_stack(t_stack **stack);
void	ft_rr(t_stack **a, t_stack **b, int p);
void	ft_ss(t_stack **a, t_stack **b, int p);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_mark_sort(t_stack **a, t_stack **b);
void	ft_push(t_stack **stack, t_stack *new);
void	ft_rrr(t_stack **a, t_stack **b, int p);
void	ft_swap_stack(t_stack **stack, char name);
void	ft_check_args(int ac, char **av, int start);
void	ft_rotate_stack(t_stack **stack, char name);
void	ft_move_push_stacks(t_stack **a, t_stack **b);
void	ft_init_stacks(t_stack **a, char **av, int ac);
void	ft_do_sort(t_stack **a, t_stack **b, size_t size);
void	ft_reverse_rotate_stack(t_stack **stack, char name);
void	ft_do_both_rot(t_stack **a, t_stack **b, t_stack *el);
void	ft_push_stack(t_stack **src, t_stack **dest, char dst);
void	ft_move_to_top(t_stack **stack, t_stack *el, char name);

int		ft_count_av(char **av);
int		ft_empty(t_stack **stack);
int		ft_min_value(int a, int b);
int		ft_is_sorted(t_stack **stack);
int		ft_index_min(t_stack **stack);
int		ft_get_index_a(t_stack **a, t_stack *el);
int		ft_get_index(t_stack **stack, t_stack *el);

size_t	ft_size(t_stack **stack);
size_t	ft_opti_rot(t_stack **stack, size_t index);

#endif