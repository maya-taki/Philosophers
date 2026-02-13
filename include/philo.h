#ifndef PHILO_H
# define PHILO_H

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


typedef struct s_data
{
	int				philo_num;
	long			time_2_eat;
	long			time_2_die;
	long			time_2_sleep;
	// int				times_must_eat;	
	// long			sim_start;
	// t_bool			sim_end;
	// pthread_mutex_t	print_mutex;
	// pthread_mutex_t	end_mutex;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	write_lock;
	// pthread_mutex_t	meal_lock;
	// pthread_mutex_t	finish_lock;
	// long			start_time;
}	t_data;

// typedef struct s_philo
// {
// 	int				id;
// 	int				meal_counter;
// 	t_bool			full;
// 	long			last_meal_time;
// 	int				*left_fork;
// 	int				*right_fork;
// 	pthread_t		thread_id; //each philo is a thread
// 	t_data			*data;

// }	t_philo;

/*##### utils #####*/
long 	ft_atol(const char *nptr);
t_bool	ft_validate_input(const char *str);
/*##### parsing #####*/
t_bool	ft_parse_args(int ac, char **av, t_data **data);
void	ft_error_exit(const char *error);
long	ft_is_negative(const char *c);
/*##### timeval #####*/
long get_time_ms(void);
t_data	*ft_init_data(int ac, char **av);




#endif