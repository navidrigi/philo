/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:12 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:51:19 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argument_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}

int	more_argument_checking(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (5);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("%d 1 has taken a fork\n", 0);
		ft_usleep(ft_atoi(argv[2]));
		printf("%d 1 died\n", ft_atoi(argv[2]) + 1);
		return (6);
	}
	if (ft_atoi(argv[2]) < 60)
		return (7);
	if (ft_atoi(argv[3]) < 60)
		return (8);
	if (ft_atoi(argv[4]) < 60)
		return (9);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (10);
	return (0);
}
