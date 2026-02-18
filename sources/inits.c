/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:09 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/18 19:44:55 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO inits


//pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
//pthread_join(philo[i].thread, NULL);

//pthread_create(&monitor, NULL, chekc_death, data);
//^loops forever
//^checks last_meal

#include "../include/philo.h"

static t_data	*ft_init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error_exit("Error.\n");
	data->philo_num= ft_atol(av[1]);
	data->time_2_die = ft_atol(av[2]) * 1e3;
	data->time_2_eat = ft_atol(av[3]) * 1e3;
	data->time_2_sleep = ft_atol(av[4]) * 1e3;
	data->times_must_eat = -1;
	// data->sim_end = 0;
	data->start_time = get_time_ms();
	if (ac == 6)
		data->times_must_eat = ft_atol(av[5]);
	return (data);
}

static	t_bool	ft_init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data)
	{
		ft_error_exit("Memory allocation failed :/");
		return (false);
	}
	while (i < data->philo_num)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->finish_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	return (true);
}

static void	*ft_init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		ft_error_exit("Memory allocation failed :/\n");
	while (i < data->philo_num)
	{
		philo[i].id =  1 + i;
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
		return (NULL);	
	philo = ft_init_philo(data);
	if (!philo)
		return (NULL);
	return (philo);
}