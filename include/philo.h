#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_rules
{
	int		philo_num;
	long	time_2_eat;
	long	time_2_die;
	long	time_2_sleep;
	int		times_must_eat;	
}			t_rules;


typedef struct s_philo
{
	int		id;
	int		meals_eaten;
}			t_philo;

/*##### utils #####*/
int	ft_atoi(const char *nptr);
long ft_atol(const char *nptr);
int	ft_is_digit(char *nbr);
/*##### parsing #####*/
int	parse_args(int ac, char **av, t_rules *rules);

#endif