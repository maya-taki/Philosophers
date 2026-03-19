/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:11 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/19 12:21:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_solo_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	ft_print_state(philo, MSG_FORK);
	ft_usleep(data->time_2_die, data);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	ft_print_state(philo, MSG_DIED);
	pthread_mutex_lock(&data->finish_lock);
	data->finished = 1;
	pthread_mutex_unlock(&data->finish_lock);
}

void	ft_lock_forks(t_philo *philo, t_data *data)
{
	if (data->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		pthread_mutex_lock(&data->forks[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		pthread_mutex_lock(&data->forks[philo->left_fork]);
	}
	if (ft_get_stop(data))
	{		
		pthread_mutex_unlock(&data->forks[philo->left_fork]);
		pthread_mutex_unlock(&data->forks[philo->right_fork]);
	}
	ft_print_state(philo, MSG_FORK);
	ft_print_state(philo, MSG_FORK);
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->philo_num == 1)
		return (ft_solo_philo(philo, data));
	ft_lock_forks(philo, data);
	pthread_mutex_lock(&data->meal_lock);
	philo->last_meal_time = ft_get_time_ms();
	philo->meal_counter++;
	pthread_mutex_unlock(&data->meal_lock);
	ft_print_state(philo, MSG_EAT);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
	ft_usleep(data->time_2_eat, data);
}

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
	ft_usleep(philo->data->time_2_sleep, philo->data);
	ft_print_state(philo, MSG_SLEEP);
}
