/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:32 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:52:43 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	int			i;
	t_param		*params;

	params = (t_param *) arg;
	while (1)
	{
		i = 0;
		while (i < params->count)
		{
			if (death_checking(&params->philos[i]))
			{
				print_status(&params->philos[i], DIE);
				pthread_mutex_lock(&params->death_flag_mutex);
				params->death_flag = 1;
				pthread_mutex_unlock(&params->death_flag_mutex);
				return (NULL);
			}
			if (all_well_fed(params))
				return (NULL);
			i++;
		}
		ft_usleep(1);
	}
	return (NULL);
}

int	death_checking(t_philo *philo)
{
	long	time_since_last_eaten;

	pthread_mutex_lock(&philo->eating_mutex);
	time_since_last_eaten = get_current_time() - philo->last_time_eaten;
	pthread_mutex_unlock(&philo->eating_mutex);
	if (time_since_last_eaten > philo->params->die_t)
		return (1);
	return (0);
}

int	repetitiv_death_checking(t_param *params)
{
	pthread_mutex_lock(&params->death_flag_mutex);
	if (params->death_flag)
	{
		pthread_mutex_unlock(&params->death_flag_mutex);
		return (1);
	}
	pthread_mutex_unlock(&params->death_flag_mutex);
	return (0);
}
