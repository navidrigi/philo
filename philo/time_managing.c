/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_managing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:50:09 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:50:11 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	static unsigned long	time = 0;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	if (!time)
	{
		time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		return (time);
	}
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - time);
}

int	ft_usleep(int m_sec)
{
	int	before;
	int	after;

	before = get_current_time();
	after = before;
	while (after - before < m_sec)
	{
		usleep(100);
		after = get_current_time();
	}
	return (0);
}
