/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:46:07 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/04 21:24:13 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_bool	ft_death_checker(t_philo *philo, t_data *data, int i)
{
	size_t	time_since_meal;

	pthread_mutex_lock(&data->meal_lock);
	time_since_meal = ft_get_time_ms() - philo[i].last_meal_time;
	pthread_mutex_unlock(&data->meal_lock);
	if (time_since_meal > data->time_2_die)
	{
		pthread_mutex_lock(&data->finish_lock);
		if (!data->finished)
		{
			ft_print_state(philo, MSG_DIED);
			data->finished = 1;
		}
		pthread_mutex_unlock(&data->finish_lock);
		return (true);
	}
	return (false);
}

static void	ft_check_done_count(t_data *data, t_philo *philo, int *done, int i)
{
	pthread_mutex_lock(&data->meal_lock);
	while ((data->times_must_eat != -1)
		&& (data->times_must_eat <= philo[i].meal_counter))
		(*done)++;
	pthread_mutex_unlock(&data->meal_lock);
}

static t_bool	ft_everyone_full(t_data *data, int done)
{
	
	if ((data->times_must_eat != -1) && (done == data->philo_num))
	{
		pthread_mutex_lock(&data->finish_lock);
		data->finished = 1;
		pthread_mutex_unlock(&data->finish_lock);
		return (true);
	}
	return (false);
}

void	*ft_monitor(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		done;
	int		i;
	
	data = philo[0].data;
	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		done = 0;
		while (i < data->philo_num)
		{
			if (ft_death_checker(&philo[i], data, i))
				return (NULL);
			ft_check_done_count(data, philo, &done, i++);
			if (ft_everyone_full(data, done))
				return (NULL);
		}
		usleep(1000);
	}
}