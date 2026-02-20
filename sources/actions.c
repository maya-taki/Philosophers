/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:11 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/19 20:53:44 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO routines

#include "../include/philo.h"

void ft_solo_philo(t_philo *philo, t_data *data);

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
	pthread_t	forks;
	pthread_mutex_init(&, NULL)	
}
