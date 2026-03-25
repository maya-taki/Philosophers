/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:00:00 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/21 00:00:00 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_stop(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->finish_lock);
	stop = data->finished;
	pthread_mutex_unlock(&data->finish_lock);
	return (stop);
}

void	ft_set_stop(t_data *data)
{
	pthread_mutex_lock(&data->finish_lock);
	data->finished = 1;
	pthread_mutex_unlock(&data->finish_lock);
}

void	ft_think(t_philo *philo)
{
	if (ft_get_stop(philo->data))
		return ;
	ft_print_state(philo, MSG_THINK);
	if (philo->data->philo_num % 2 != 0)
		usleep(1000);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_get_stop(philo->data))
		return ;
	ft_print_state(philo, MSG_SLEEP);
	ft_usleep(philo->data->time_2_sleep, philo->data);
}
