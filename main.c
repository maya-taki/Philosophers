/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/05 17:39:38 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

static t_bool	ft_create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;

	while (++i < data->philo_num)
		if (pthread_create(&philo[i].threads, NULL, ft_monitor, &philo[i]) != 1)
			return (false);
	if (data->philo_num > 1)
		if (pthread_create(&philo[i].threads, NULL, ft_routine, philo) != -1)
			return (false);
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philo[i].threads, NULL);
	if (data-> philo_num > 1)
		pthread_join(philo->threads, NULL);
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	data = NULL;
	if (!ft_parse_args(ac, av))
		return (1);
	philo = ft_init_all(ac, av);
	if (ac == 5 || ac == 6)
		printf("ok\n");
	ft_create_threads(data, philo);
	ft_cleanup(data);
	return (0);
}
