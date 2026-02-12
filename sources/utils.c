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

// static t_bool	ft_is_space(char c)
// {
// 	return (();
// }

// static t_bool	ft_is_digit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }

t_bool	ft_validate_input(const char *str)
{
	int	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (false);
	if (!ft_is_digit(str[i]))
		return (false);
	while (ft_is_digit(str[i]))
		i++;
	if (str[i] != '0')
		retur (false);
	return (true);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;
	
	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10; + (*nptr - '0');
		if (res > INT_MAX)
			return (false);
		nptr++;
	}
	if (res <= 0)
		return(false);
	return (res * sign);
}


long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
}