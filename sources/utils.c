/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:45:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/19 12:15:01 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
}

int	ft_put_error(const char *error)
{
	int	i;

	i = 0;
	while (error[i])
		i++;
	write(2, error, i);
	write(2, "\n", 1);
	return (0);
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

void	ft_usleep(long duration, t_data *data)
{
	long	start_time;

	start_time = (long)ft_get_time_ms();
	while (ft_get_time_ms() - start_time < duration)
	{
		if (ft_get_stop(data))
			break ;
		usleep(1000);
	}
}

void	*ft_print_state(t_philo *philo, const char *state)
{
	int	stop;

	pthread_mutex_lock(&philo->data->finish_lock);
	stop = philo->data->finished;
	pthread_mutex_unlock(&philo->data->finish_lock);
	pthread_mutex_lock(&philo->data->write_lock);
	if (!stop)
		printf("%ld %d %s\n",
			ft_get_time_ms() - philo->data->start_time, philo->id, state);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (NULL);
}
