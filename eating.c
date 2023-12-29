/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:40 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:58:04 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (repetitiv_death_checking(philo->params))
		return ;
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->params->count_well_fed_mutex);
	pthread_mutex_lock(&philo->meals_eaten_mutex);
	if (philo->params->meals_n != -1)
	{
		philo->meals_eaten++;
		philo->params->count_well_fed++;
	}
	pthread_mutex_unlock(&philo->meals_eaten_mutex);
	pthread_mutex_unlock(&philo->params->count_well_fed_mutex);
	pthread_mutex_lock(&philo->eating_mutex);
	philo->last_time_eaten = get_current_time();
	pthread_mutex_unlock(&philo->eating_mutex);
	ft_usleep(philo->params->eat_t);
	leaving_forks(philo);
}

int	all_well_fed(t_param *params)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&params->count_well_fed_mutex);
	if (params->count_well_fed == params->count * params->meals_n)
		flag = 1;
	pthread_mutex_unlock(&params->count_well_fed_mutex);
	return (flag);
}
