/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:59 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:57:59 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routin(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		if (repetitiv_death_checking(philo->params))
			break ;
		if (!(philo->id % 2)
			|| (philo->id % 2 && philo->id == philo->params->count))
			thinking(philo);
		taking_forks(philo);
		eating(philo);
		pthread_mutex_lock(&philo->meals_eaten_mutex);
		if (philo->meals_eaten == philo->params->meals_n)
		{
			pthread_mutex_unlock(&philo->meals_eaten_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meals_eaten_mutex);
		sleeping(philo);
		thinking(philo);
		if (repetitiv_death_checking(philo->params))
			break ;
	}
	return (NULL);
}
