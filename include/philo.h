/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:33:40 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/03/19 12:21:40 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

# define MSG_EAT "is eating"
# define MSG_FORK "has taken a fork"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_DIED "has died"

typedef struct s_philo	t_philo;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_data
{
	int				philo_num;
	long			time_2_eat;
	long			time_2_die;
	long			time_2_sleep;
	int				times_must_eat;	
	long			start_time;
	t_bool			finished;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	finish_lock;
	pthread_t		monitor_thread;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_counter;
	long			last_meal_time;
	int				left_fork;
	int				right_fork;
	pthread_t		threads;
	t_data			*data;
}	t_philo;

/*##### utils #####*/
void	*ft_cleanup(t_data *data);
void	ft_usleep(long duration, t_data *data);
long	ft_get_time_ms(void);
void	*ft_print_state(t_philo *philo, const char *state);
int		ft_put_error(const char *error);
/*##### parsing #####*/
t_bool	ft_parse_args(int ac, char **av);
long	ft_atol(const char *nptr);
/*##### inits #####*/
t_philo	*ft_init_all(int ac, char **av);
/*##### actions #####*/
void	ft_eat(t_philo *philo);
t_bool	ft_lock_forks(t_philo *philo, t_data *data);
void	ft_solo_philo(t_philo *philo, t_data *data);
/*##### state #####*/
int		ft_get_stop(t_data *data);
void	ft_set_stop(t_data *data);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);
/*##### monitor #####*/
void	*ft_monitor(void *arg);
/*##### runtime #####*/
void	*ft_routine(void *arg);

#endif
