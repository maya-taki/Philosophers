/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 21:00:17 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/03 21:07:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO

#include "../include/philo.h"

void	ft_sim_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->end_mutex);
	philo->simulation_end = 1;
	pthread_mutex_unlock(&philo->end_mutex);
}