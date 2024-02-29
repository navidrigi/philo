/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_join_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:27 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:52:10 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_param *params)
{
	int	i;

	i = 0;
	while (i < params->count)
	{
		params->philos[i].id = i + 1;
		params->philos[i].meals_eaten = 0;
		params->philos[i].params = params;
		params->philos[i].last_time_eaten = get_current_time();
		pthread_create(&params->philos[i].thread, NULL, routin,
			&params->philos[i]);
		ft_usleep(500);
		i++;
	}
	pthread_create(&params->monitor, NULL, monitor, (void *)params);
}

void	join_threads(t_param *params)
{
	int	i;

	i = 0;
	while (i < params->count)
	{
		pthread_join(params->philos[i].thread, NULL);
		i++;
	}
	pthread_join(params->monitor, NULL);
}
