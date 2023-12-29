/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:50:04 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:50:05 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	if (repetitiv_death_checking(philo->params))
		return ;
	print_status(philo, SLEEP);
	ft_usleep(philo->params->sleep_t);
}
