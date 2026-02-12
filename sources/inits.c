/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:06:09 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/11 21:05:04 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO inits


//pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
//pthread_join(philo[i].thread, NULL);

//pthread_create(&monitor, NULL, chekc_death, data);
//^loops forever
//^checks last_meal

#include "../include/philo.h"

void	ft_init_philo(int ac, char **av);

void	ft_init_forks(t_philo *philo)
{	
	int	left;
	int	right;
	
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->right_fork);
	//code
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	ft_data_init(t_data *data);
