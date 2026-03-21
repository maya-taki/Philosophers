/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/21 00:00:00 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	ft_create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_create(&philo[i].threads, NULL,
				ft_routine, &philo[i]) != 0)
			return (TRUE);
	}
	if (data->philo_num > 1)
	{
		if (pthread_create(&data->monitor_thread, NULL,
				ft_monitor, philo) != 0)
			return (TRUE);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philo[i].threads, NULL);
	if (data->philo_num > 1)
		pthread_join(data->monitor_thread, NULL);
	return (FALSE);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (!ft_parse_args(ac, av))
	{
		ft_put_error("Invalid arguments");
		return (1);
	}
	philo = ft_init_all(ac, av);
	if (!philo)
	{
		ft_put_error("Initialization failed");
		return (1);
	}
	if (ft_create_threads(philo[0].data, philo))
	{
		ft_cleanup(philo[0].data);
		free(philo);
		return (1);
	}
	ft_cleanup(philo[0].data);
	free(philo);
	return (0);
}
