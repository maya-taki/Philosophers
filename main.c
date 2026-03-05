/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/04 21:26:38 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

t_bool	ft_create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		// if (pthread_create(&philo[i].thread_id, NULL, ft_routine, &philo[i]) != 0)
		// 	return (false);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_create(&philo[i].thread_id, NULL, ft_monitor, &philo[i]) != 0)
			return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	
	if (!ft_parse_args(ac, av))
		return (1);
	philo = ft_init_all(ac, av);
	if (ac == 5 || ac == 6)
		printf("ok\n");
	ft_create_threads(data, philo);
	free(ft_init_all(ac, av));
	return (0);
}