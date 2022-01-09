/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbordere <bbordere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:55:24 by bbordere          #+#    #+#             */
/*   Updated: 2022/01/06 16:22:50 by bbordere         ###   ########.fr       */
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

void	ft_error(int ac, char **av)
{
	if (ac == 2)
		ft_free(av);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_valid_num(int ac, char **av, char *n)
{
	long long		temp;
	size_t			i;

	i = -1;
	if (ft_strlen(n) == 1 && (n[0] == '+' || n[0] == '-'))
		ft_error(ac, av);
	while (n[++i])
		if (!ft_isdigit(n[i]) && n[i] != '-' && n[i] != '+')
			ft_error(ac, av);
	i = 0;
	while (n[++i])
		if (n[i] == '+' || n[i] == '-')
			ft_error(ac, av);
	temp = ft_atoll(n);
	if (temp > MAX_INT || temp < MIN_INT)
		ft_error(ac, av);
}

void	ft_doublon(int n, int ac, char **av, int i)
{
	while (av[++i])
		if (ft_atoll(av[i]) == n)
			ft_error(ac, av);
}

void	ft_check_args(int ac, char **av, int start)
{
	int	i;

	if (ac == 1)
		exit(0);
	i = start;
	while (av[i])
	{
		if (!av[i])
			ft_error(ac, av);
		if ((ft_strlen(av[i]) > 11 && (av[i][0] != '+' || av[i][0] != '-')))
			if (av[i][1] != '0')
				ft_error(ac, av);
		ft_valid_num(ac, av, av[i]);
		ft_doublon(ft_atoi(av[i]),ac, av, i);
		i++;
	}
}
