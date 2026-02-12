#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

typedef enum s_bool 
{
	false = 0,
	true = 1
}	t_bool;


typedef struct s_fork
{
	pthread_mutex_t	forks;
	int				fork_id;
}	t_fork;

typedef struct s_data
{
	int				philo_num;
	long			time_2_eat;
	long			time_2_die;
	long			time_2_sleep;
	int				times_must_eat;	

	long			sim_start;
	t_bool			sim_end;
	
	t_fork			*forks;
	t_philo			*philos;

	pthread_mutex_t	print_mutex;
	pthread_mutex_t	end_mutex;

	long			start_time;
}	t_data;

typedef struct	s_waiter
{
	//checks if philo dies
	//gives forks to philos
	//checks if everyone is eating correctly
}	t_waiter;

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	t_bool			full;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id; //each philo is a thread
	t_data			*data;

}	t_philo;

/*##### utils #####*/
t_bool 	ft_atol(const char *nptr);
t_bool	ft_validate_input(const char *str);
/*##### parsing #####*/
t_bool	ft_parse_args(int ac, char **av, t_data *rules);
void	ft_error_exit(const char *error);
/*##### timeval #####*/
long get_time_ms(void);


#endif