/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:55:24 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/05 16:41:28 by bbordere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long ft_atoll(char *str)
{
	long long	i;
	long long	res;
	int	s;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' && str[i])
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+' && str[i])
		i++;
	while (ft_isdigit(str[i]) && str[i])
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (s * res);
}

void	ft_error()
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	ft_valid_num(char *n)
{
	long long		temp;
	size_t	i;

	i = -1;
	while (n[++i])
		if (!ft_isdigit(n[i]) && n[i] != '-' && n[i] != '+')
			ft_error();
	temp = ft_atoll(n);
	if (temp > MAX_INT || temp < MIN_INT)
		ft_error();
}

void	ft_doublon(int n, char **av, int i)
{
	while (av[++i])
		if (ft_atoll(av[i]) == n)
			ft_error();
}

void	ft_check_args(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!av[0])
			exit(0);
	}
	else
		i = 1;
	while (av[i])
	{
		ft_valid_num(av[i]);
		ft_doublon(ft_atoi(av[i]), av, i);
		i++;
	}
}
