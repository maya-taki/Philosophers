/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:48:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/26 19:47:45 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_bool	ft_is_digit(const char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (false);
		i++;
	}
		return (true);
}

t_bool	ft_parse_args(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 5 || ac > 6)
		ft_error_exit("Invalid number of arguments");
	while (i < ac)
	{
		if (!ft_is_digit(av[i]))
			ft_error_exit("Ur doing it wrong");
		i++;
	}
	return (true);
}

static long	ft_is_negative(const char *c)
{
	while (*c == '+' || *c == '-')
	{
		if (*c == '-')
			ft_error_exit("I can only accept positive arguments :(");
		c++;
	}
	return (0);
}

static int	ft_is_alpha(const char *c)
{
	while (*c)
	{
		if (*c >= 'a' && *c <= 'z' || *c >= 'A' && *c <= 'Z')
			ft_error_exit("No letters allowed :p");
		c++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	res;
	
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			ft_is_negative(nptr);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		if (res > INT_MAX)
			return (0);
		nptr++;
	}
	if ((*nptr == '+' || *nptr == '-') || (ft_is_alpha(nptr)))
		return (0);
	return (res);
}