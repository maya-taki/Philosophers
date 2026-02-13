/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:18 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/12 13:32:13 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO waiters

#include "../include/philo.h"


void	ft_sim_end(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->sim_end = 1;
	pthread_mutex_unlock(&data->end_mutex);
}