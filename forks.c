/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:43 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:53:14 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *philo)
{
	if (repetitiv_death_checking(philo->params))
		return ;
	if (philo->id == 1)
		first_philo_taking_forks(philo);
	else
		other_philos_taking_forks(philo);
	if (repetitiv_death_checking(philo->params))
		return ;
	print_status(philo, FORK);
	print_status(philo, FORK);
}

int	first_philo_taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[0]);
	pthread_mutex_lock(&philo->params->forks[philo->params->count - 1]);
	return (0);
}

int	other_philos_taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[philo->id - 2]);
	pthread_mutex_lock(&philo->params->forks[philo->id - 1]);
	return (0);
}

void	leaving_forks(t_philo *philo)
{
	if (philo->id == 1)
	{
		pthread_mutex_unlock(&philo->params->forks[philo->params->count - 1]);
		pthread_mutex_unlock(&philo->params->forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->params->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->params->forks[philo->id - 2]);
	}
}
