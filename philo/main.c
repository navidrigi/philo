/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narigi-e <narigi-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:49:51 by narigi-e          #+#    #+#             */
/*   Updated: 2023/12/29 14:54:17 by narigi-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_param	*params;

	if (argc == 5 || argc == 6)
	{
		if (argument_check(argv) || more_argument_checking(argc, argv))
			return (1);
		params = initialize(argc, argv);
		init_mutexes(params);
		create_threads(params);
		join_threads(params);
		cleanup(params);
	}
	else
		write (2, "Wrong number of Arguments\n", 26);
	return (0);
}
