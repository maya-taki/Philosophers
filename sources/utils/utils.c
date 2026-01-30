/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/30 17:36:31 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned int	res;
	int				sign;
	
	sign = 0;
	i = 0;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{	
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = nptr[i] * 10;
		res += nptr[i] - '0';
		i++;
	}
	return (sign * res);
}

long ft_atol(const char *nptr)
{
	int		i;
	long	res;
	
	i = 0;
	res = 0;
	
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = nptr[i] * 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res);
}
int	ft_is_digit(char *nbr)
{
	int	i;
	
	i = 0;
	if (!nbr || nbr[i] == '\0')
		return (0);
	while (nbr[i])
	{
		if (nbr[i] < 48 || nbr[i] > 57)
			return (0);
		i++;
	}
	return (1);	
}