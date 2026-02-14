/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:09 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/13 21:42:46 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO inits


//pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
//pthread_join(philo[i].thread, NULL);

//pthread_create(&monitor, NULL, chekc_death, data);
//^loops forever
//^checks last_meal

#include "../include/philo.h"

t_data	*ft_init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(data));
	if (!data)
		ft_error_exit("Error.\n");
	data->philo_num= ft_atol(av[1]);
	data->time_2_die = ft_atol(av[2]) * 1e3;
	data->time_2_eat = ft_atol(av[3]) * 1e3;
	data->time_2_sleep = ft_atol(av[4]) * 1e3;
	data->times_must_eat = -1;
	// data->sim_end = 0;
	// data->start_time = get_time_ms();
	// if (ac == 6)
	// 	data->times_must_eat = ft_atol(av[5]);
	return (data);
}


// void	ft_init_philo(int ac, char **av)
// {
// 	t_philo	*philo;

// 	if (!philo)
// 		ft_error_exit("Error.\n");
// 	philo->data = 0;
// 	philo->full = 0;
// 	philo->id = 0;
// 	philo->last_meal_time = 0;
// 	philo->left_fork = 0;
// 	philo->right_fork = 0;
// 	philo->meal_counter = -1;
// 	philo->thread_id = 0;	
// }


// void	ft_init_forks(t_philo *philo)
// {	
// 	int	left;
// 	int	right;
	
// 	pthread_mutex_lock(&philo->left_fork);
// 	pthread_mutex_lock(&philo->right_fork);
// 	//code
// 	pthread_mutex_unlock(&philo->left_fork);
// 	pthread_mutex_unlock(&philo->right_fork);
// }
