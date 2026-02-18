/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:48:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/02/18 17:43:13 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_bool	ft_parse_args(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 5 || ac > 6)
		ft_error_exit("Invalid number of arguments");
	while (i < ac)
	{
		if (!ft_atol(av[i]))
			ft_error_exit("Ur doing it wrong");
		i++;
	}
	return (true);
}
