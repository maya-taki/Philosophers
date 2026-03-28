/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:46:07 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/27 23:17:34 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	ft_death_checker(t_philo *philo, t_data *data, int i)
{
	long	time_since_meal;

	pthread_mutex_lock(&data->meal_mutex);
	time_since_meal = ft_get_time_ms() - philo[i].last_meal_time;
	pthread_mutex_unlock(&data->meal_mutex);
	if (time_since_meal > data->time_2_die)
	{
		if (!ft_get_stop(data))
		{
			ft_print_state(&philo[i], MSG_DIED);
			ft_set_stop(data);
		}
		return (TRUE);
	}
	return (FALSE);
}

static void	ft_check_done_count(t_data *data, t_philo *philo, int *done, int i)
{
	pthread_mutex_lock(&data->meal_mutex);
	if ((data->times_must_eat != -1)
		&& (data->times_must_eat <= philo[i].meal_counter))
		(*done)++;
	pthread_mutex_unlock(&data->meal_mutex);
}

static t_bool	ft_everyone_full(t_data *data, int done)
{
	if ((data->times_must_eat != -1) && (done == data->philo_num))
	{
		ft_set_stop(data);
		return (TRUE);
	}
	return (FALSE);
}

void	*ft_monitor(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		done;
	int		i;

	philo = (t_philo *)arg;
	data = philo[0].data;
	while (1)
	{
		i = 0;
		done = 0;
		while (i < data->philo_num)
		{
			if (ft_death_checker(philo, data, i))
				return (NULL);
			ft_check_done_count(data, philo, &done, i);
			if (ft_everyone_full(data, done))
				return (NULL);
			i++;
		}
		usleep(1000);
	}
}
