
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

long	ft_is_negative(const char *c)
{
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			ft_error_exit("I can only accept positive arguments :(");
		c++;
	}
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	res;
	
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			ft_is_negative(nptr);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		if (res > INT_MAX)
			return (0);
		nptr++;
	}
	return (res);
}

long	ft_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + tv.tv_usec / 1000));
}

// void	*ft_cleanup(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->philo_num)
// 		pthread_mutex_destroy(&data->forks[i++]);
// 	pthread_mutex_destroy(&data->write_lock);
// 	pthread_mutex_destroy(&data->meal_lock);
// 	pthread_mutex_destroy(&data->finish_lock);
// 	free(data->forks);
// 	free(data);
// }

void	ft_usleep(long duration, t_data	*data)
{
	long	start_time;

	start_time = (long)get_time_ms();
	while (get_time_ms() - start_time < duration)
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
		printf("%-51d %-2d %s",
			ft_get_time_ms() - philo->data->start_time, philo->id, state);
	pthread_mutex_unlock(&philo->data->finish_lock);
}