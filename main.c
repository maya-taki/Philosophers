/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/24 11:33:34 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
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

	free(ft_init_all(ac, av));
	return (0);
}

	// ft_dinner_start(&data); //TODO

	// //No leaks -> philos full | 1 philo dead
	// ft_clean(&data); //TODO
	// pthread_mutex_init();
	// pthread_create();
	// pthread_join();
	// pthread_destroy();