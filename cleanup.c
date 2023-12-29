/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:23 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:51:33 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_param *params)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&params->print_mutex);
	pthread_mutex_destroy(&params->count_well_fed_mutex);
	pthread_mutex_destroy(&params->eating_mutex);
	pthread_mutex_destroy(&params->death_flag_mutex);
	while (i < params->count)
		pthread_mutex_destroy(&params->forks[i++]);
	i = 0;
	while (i < params->count)
		pthread_mutex_destroy(&params->philos[i++].eating_mutex);
	i = 0;
	while (i < params->count)
		pthread_mutex_destroy(&params->philos[i++].meals_eaten_mutex);
	free(params->philos);
	free(params->forks);
	free(params);
}
