/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:48 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:54:01 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	*initialize(int argc, char **argv)
{
	t_param	*params;

	params = (t_param *) malloc(sizeof(t_param));
	params->count = ft_atoi(argv[1]);
	params->philos = malloc (params->count * sizeof(t_philo));
	params->die_t = ft_atoi(argv[2]);
	params->eat_t = ft_atoi(argv[3]);
	params->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
		params->meals_n = ft_atoi(argv[5]);
	else
		params->meals_n = -1;
	params->death_flag = 0;
	params->count_well_fed = 0;
	return (params);
}
