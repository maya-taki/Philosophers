/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:48:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/26 16:26:02 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	ft_is_digit(const char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ft_parse_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (FALSE);
	while (i < ac)
	{
		if (!ft_is_digit(av[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long	ft_atol(const char *nptr)
{
	long	res;

	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		if (res > INT_MAX)
			return (-1);
		nptr++;
	}
	return (res);
}
