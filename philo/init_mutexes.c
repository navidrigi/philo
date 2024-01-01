/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:45 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:53:47 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_param *params)
{
	int	i;

	i = 0;
	params->forks = malloc(params->count * sizeof(pthread_mutex_t));
	if (!params->forks)
		return ;
	pthread_mutex_init(&params->print_mutex, NULL);
	pthread_mutex_init(&params->count_well_fed_mutex, NULL);
	pthread_mutex_init(&params->eating_mutex, NULL);
	pthread_mutex_init(&params->death_flag_mutex, NULL);
	while (i < params->count)
		pthread_mutex_init(&params->forks[i++], NULL);
	i = 0;
	while (i < params->count)
		pthread_mutex_init(&params->philos[i++].eating_mutex, NULL);
	i = 0;
	while (i < params->count)
		pthread_mutex_init(&params->philos[i++].meals_eaten_mutex, NULL);
}
