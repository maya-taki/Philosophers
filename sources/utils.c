
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/11 21:25:07 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
}

void	*ft_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->finish_lock);
	free(data->forks);
	free(data);
	return (NULL);
}

void	ft_usleep(long duration, t_data	*data)
{
	long	start_time;

	start_time = (long)ft_get_time_ms();
	while (ft_get_time_ms() - start_time < duration)
	{
		pthread_mutex_lock(&data->end_mutex);
		if (data->sim_end == 1)
		{
			pthread_mutex_unlock(&data->end_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->end_mutex);
		usleep(500);
	}
}
void	*ft_print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->data->finish_lock);
	if (!philo->data->finished)
		printf("%-51ld %-2d %s",
			ft_get_time_ms() - philo->data->start_time, philo->id, state);
	pthread_mutex_unlock(&philo->data->finish_lock);
	return (NULL);
}