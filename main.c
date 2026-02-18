/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:17:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/18 19:42:54 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

//./philo 5 800 200 200 [5]

void	ft_error_exit(const char *error)
{
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	// pthread_t	*thread;
	
	if (!ft_parse_args(ac, av))
		return (0);
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