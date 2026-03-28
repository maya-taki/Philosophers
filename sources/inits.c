/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:09 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/27 23:16:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_data	*ft_init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = ft_atol(av[1]);
	data->time_2_die = ft_atol(av[2]);
	data->time_2_eat = ft_atol(av[3]);
	data->time_2_sleep = ft_atol(av[4]);
	data->times_must_eat = -1;
	data->finished = 0;
	data->start_time = ft_get_time_ms();
	if (ac == 6)
	{
		data->times_must_eat = ft_atol(av[5]);
		if (data->times_must_eat < 1)
			return (free(data), NULL);
	}
	if (data->philo_num < 1 || data->time_2_die < 1
		|| data->time_2_eat < 1 || data->time_2_sleep < 1)
		return (free(data), NULL);
	return (data);
}

static t_bool	ft_init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks_mutex)
		return (FALSE);
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks_mutex[i++], NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
	return (TRUE);
}

static t_philo	*ft_init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		return (NULL);
	while (i < data->philo_num)
	{
		philo[i].id = 1 + i;
		philo[i].data = data;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % data->philo_num;
		philo[i].meal_counter = 0;
		philo[i].last_meal_time = data->start_time;
		i++;
	}
	return (philo);
}

t_philo	*ft_init_all(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	data = ft_init_data(ac, av);
	if (!data)
		return (NULL);
	if (!ft_init_mutexes(data))
		return (free(data), NULL);
	philo = ft_init_philo(data);
	if (!philo)
		return (ft_cleanup(data), NULL);
	data->philo = philo;
	return (philo);
}
