/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:48:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/12 14:29:16 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_bool	ft_parse_args(int ac, char **av, t_data *data)
{
	int		i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (false);
	while (i < ac)
	{
		if (!ft_atol(av[i]))
			return (false);
		i++;
	}
	ft_init_data(ac, av, data);
	if (data->philo_num <= 0 || data->time_2_die <= 0
		|| data->time_2_eat <= 0 || data->time_2_sleep <= 0)
		{
			if (ac == 6 && data->times_must_eat <= 0)
				return (false);
			return (false);
		}
	return (true);
}
