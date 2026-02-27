#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

# define MSG_EATING "is eating"
# define MSG_FORK "has taken a fork"
# define MSG_SLEEP "is sleeping"
# define MSG_THINKING "is thinking"
# define MSG_DIED "has died"

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
	int				times_must_eat;	
	int				finished;
	// long			sim_start;
	t_bool			sim_end;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	finish_lock;
	long			start_time;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	long			last_meal_time;
	int				left_fork;
	int				right_fork;
	pthread_t		thread_id; //each philo is a thread
	// 	t_bool			full;
	t_data			*data;
}	t_philo;

/*##### utils #####*/
void	*ft_cleanup(t_data *data);
void	ft_usleep(long duration, t_data	*data);
long 	ft_get_time_ms(void);
void	*ft_print_state(t_philo *philo, const char *state);
/*##### parsing #####*/
t_bool	ft_parse_args(int ac, char **av);
void	ft_error_exit(const char *error);
long 	ft_atol(const char *nptr);
/*##### inits #####*/
t_philo	*ft_init_all(int ac, char **av);
/*##### actions #####*/
void	ft_lock_forks(t_philo *philo, t_data *data);
void 	ft_solo_philo(t_philo *philo, t_data *data);
/*##### monitor #####*/
void	*ft_monitor(void *arg);

#endif