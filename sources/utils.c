
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/11 21:25:07 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_is_negative(const char *c)
{
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			ft_error_exit("I can only accept positive arguments :(");
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
	return (res);
}

// t_bool	ft_is_negative(char **av)
// {
// 	int	i;

// 	i = 1;
// 	while (av[i][0])
// 	{
// 		if (av[i][0] == '-')
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }


// long	get_time_ms(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
// }
