/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:48:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/01/30 17:29:18 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av, t_rules *rules)
{
	int	i;

	i = 0;
	rules->philo_num= ft_atoi(av[1]);
	rules->time_2_die = ft_atol(av[2]);
	rules->time_2_eat = ft_atol(av[3]);
	rules->time_2_sleep = ft_atol(av[4]);
	if (ac < 5 || ac > 6)
		return (1);
	if (i < ac)
	{
		if (!is_digit(av[i]))
			return (1);
		i++;
	}
	if (ac == 6)
		rules->times_must_eat = ft_atoi(av[5]);
	if (rules->philo_num >= 0 || rules->time_2_die >= 0 || rules->time_2_eat >= 0 || rules->time_2_sleep >= 0 || rules->times_must_eat >= 0)
		return (1);
	return (0);
}
