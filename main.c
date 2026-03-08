/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/08 18:53:10 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

static t_bool	ft_create_threads(t_data *data, t_philo *philo)
{
	int	i;
	
	i = -1;
	while (++i < data->philo_num)
	{
		printf("philo created\n");
		if (pthread_create(&philo[i].threads, NULL, ft_routine, &philo[i]) != 0)
			return (true);
	}
	if (data->philo_num > 1)
	{
		printf("ok 2\n");
		if (pthread_create(&data->monitor_thread, NULL, ft_monitor, philo) != 0)
			return (true);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philo[i].threads, NULL);
	if (data-> philo_num > 1)
		pthread_join(data->monitor_thread, NULL);
	return (false);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	data = NULL;
	if (!ft_parse_args(ac, av))
		return (1);
	philo = ft_init_all(ac, av);
	if (!philo)
		return (1);
	while (!ft_create_threads(philo[0].data, philo))
	{
		ft_cleanup(data);
		free(philo);
		return (1);
	}
	ft_cleanup(philo[0].data);
	free(philo);
	return (0);
}
