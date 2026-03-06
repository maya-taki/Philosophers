/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:18 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/06 16:32:36 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static t_bool	ft_should_continue(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->finish_lock);
	if (data->finished)
	{
		pthread_mutex_unlock(&data->finish_lock);
		return (false);
	}
	pthread_mutex_unlock(&data->finish_lock);
	pthread_mutex_lock(&data->meal_lock);
	if ((data->times_must_eat = -1) && (philo->meal_counter >= data->times_must_eat))
	{
		pthread_mutex_unlock(&data->meal_lock);
		return (false);
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (true);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	
	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(100);
	while(1)
	{
		printf("test\n");
		if (!ft_should_continue(philo, data))
			break ;
		ft_eat(philo);
		ft_print_state(philo, MSG_SLEEP);
		ft_usleep(data->time_2_sleep, data);
		ft_print_state(philo, MSG_THINKING);
	}
	return (NULL);
}
