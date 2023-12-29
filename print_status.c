/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:57 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:54:36 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, int act)
{
	pthread_mutex_lock(&philo->params->print_mutex);
	if (act == FORK)
		printf("%ld %d has taken a fork\n", get_current_time(), philo->id);
	else if (act == EAT)
		printf(GREEN "%ld %d is eating" RESET "\n", get_current_time(),
			philo->id);
	else if (act == SLEEP)
		printf("%ld %d is sleeping\n", get_current_time(), philo->id);
	else if (act == THINK)
		printf("%ld %d is thinking\n", get_current_time(), philo->id);
	else if (act == DIE)
		printf(RED "%ld %d died" RESET "\n", get_current_time(), philo->id);
	pthread_mutex_unlock(&philo->params->print_mutex);
}
