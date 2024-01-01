/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:54 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:56:41 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <errno.h>
# include <sys/time.h>
# include <sys/wait.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"
# define ORANGE "\033[1;31m"

enum	e_acts
{
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIE
};

typedef struct s_param	t_param;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long				last_time_eaten;
	pthread_t			thread;
	t_param				*params;
	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		meals_eaten_mutex;
	int					death_flag;
	pthread_mutex_t		death_flag_mutex;
}				t_philo;

struct s_param
{
	int					count;
	long				die_t;
	long				eat_t;
	long				sleep_t;
	int					meals_n;
	int					count_well_fed; // shared
	pthread_mutex_t		count_well_fed_mutex;
	int					death_flag; // shared
	pthread_t			monitor;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		death_flag_mutex;
};

int			argument_check(char **argv);
int			all_well_fed(t_param *params);
void		cleanup(t_param *params);
void		create_threads(t_param *params);
int			death_checking(t_philo *philo);
void		eating(t_philo *philo);
int			first_philo_taking_forks(t_philo *philo);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_usleep(int usec);
long		get_current_time(void);
void		init_mutexes(t_param *params);
t_param		*initialize(int argc, char **argv);
void		join_threads(t_param *params);
void		leaving_forks(t_philo *philo);
void		*monitor(void *arg);
int			more_argument_checking(int argc, char **argv);
int			other_philos_taking_forks(t_philo *philo);
void		print_status(t_philo *philo, int act);
void		*routin(void *arg);
void		sleeping(t_philo *philo);
void		taking_forks(t_philo *philo);
void		thinking(t_philo *philo);
int			repetitiv_death_checking(t_param *params);

#endif
