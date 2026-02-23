/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:11 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/23 01:08:55 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO routines

#include "../include/philo.h"

void ft_solo_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks[philo->left_fork]);
	ft_print_state(philo, MSG_FORK);
	ft_usleep(data->time_2_die, data);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	ft_print_state(philo, MSG_DIED);
	pthread_mutex_lock(&data->finish_lock);
	data->sim_end = 1;
	pthread_mutex_unlock(&data->finish_lock);
}

void	ft_lock_forks(t_philo *philo, t_data *data)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		pthread_mutex_lock(&data->forks[philo->right_fork]);
	}
	else
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		pthread_mutex_lock(&data->forks[philo->right_fork]);
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->philo_num == 1)
		ft_solo_philo(philo, data);
	ft_lock_forks(philo, data);
	pthread_mutex_lock(&data->meal_lock);
	philo->last_meal_time = ft_get_time_ms();
	philo->meal_counter++;
	pthread_mutex_unlock(&data->meal_lock);
	ft_print_state(philo, MSG_EATING);
	ft_usleep(data->time_2_eat, data);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}
