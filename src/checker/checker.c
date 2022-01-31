/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:10:00 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:51 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_checker(t_stack **a, t_stack **b, char *cmd)
{
	free(cmd);
	ft_putendl_fd("Error", 2);
	ft_free_stack(a);
	ft_free_stack(b);
	exit(1);
}

void	ft_do_op(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		ft_swap_stack(a, ' ');
	else if (!ft_strncmp(cmd, "sb\n", 3))
		ft_swap_stack(b, ' ');
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ft_ss(a, b, 0);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ft_rotate_stack(a, ' ');
	else if (!ft_strncmp(cmd, "rb\n", 3))
		ft_rotate_stack(b, ' ');
	else if (!ft_strncmp(cmd, "rr\n", 3))
		ft_rr(a, b, 0);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		ft_reverse_rotate_stack(a, ' ');
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		ft_reverse_rotate_stack(b, ' ');
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		ft_rrr(a, b, 0);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		ft_push_stack(a, b, ' ');
	else if (!ft_strncmp(cmd, "pa\n", 3))
		ft_push_stack(b, a, ' ');
	else
		ft_error_checker(a, b, cmd);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	a = NULL;
	b = NULL;
	ft_init_stacks(&a, av, ac);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		ft_do_op(&a, &b, cmd);
		free(cmd);
	}
	if (ft_is_sorted(&a) && ft_empty(&b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
