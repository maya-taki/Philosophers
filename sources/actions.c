/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:11 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/30 21:09:01 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_solo_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->forks_mutex[philo->left_fork]);
	ft_print_state(philo, MSG_FORK);
	ft_usleep(data->time_2_die, data);
	pthread_mutex_unlock(&data->forks_mutex[philo->left_fork]);
	ft_print_state(philo, MSG_DIED);
	ft_set_stop(data);
}

static void	ft_set_forks(t_philo *philo, int *first, int *second)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

t_bool	ft_lock_forks(t_philo *philo, t_data *data)
{
	int	first;
	int	second;

	if (ft_get_stop(data))
		return (FALSE);
	ft_set_forks(philo, &first, &second);
	pthread_mutex_lock(&data->forks_mutex[first]);
	pthread_mutex_lock(&data->forks_mutex[second]);
	if (ft_get_stop(data))
	{
		pthread_mutex_unlock(&data->forks_mutex[second]);
		pthread_mutex_unlock(&data->forks_mutex[first]);
		return (FALSE);
	}
	ft_print_state(philo, MSG_FORK);
	ft_print_state(philo, MSG_FORK);
	return (TRUE);
}

void	ft_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->philo_num == 1)
		return (ft_solo_philo(philo, data));
	if (!ft_lock_forks(philo, data))
		return ;
	if (ft_get_stop(philo->data))
		return ;
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal_time = ft_get_time_ms();
	philo->meal_counter++;
	pthread_mutex_unlock(&data->meal_mutex);
	ft_print_state(philo, MSG_EAT);
	ft_usleep(data->time_2_eat, data);
	pthread_mutex_unlock(&data->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&data->forks_mutex[philo->right_fork]);
}
