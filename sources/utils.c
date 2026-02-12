/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/11 20:40:25 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_bool	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

static t_bool	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

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

t_bool	ft_atol(const char *nptr)
{
	long	res;
	int		i;
	
	i = 0;
	res = 0;

	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '+')
		i++;
	while (ft_is_digit(nptr[i]))
	{
		res = res * 10; + (nptr[i] - '0');
		if (res > INT_MAX)
			return (false);
		i++;
	}
	if (res <= 0)
		return(false);
	return (true);
}


long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
}