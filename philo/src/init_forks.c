/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:17:25 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/15 02:28:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;
	
	data->forks = safe_malloc(data->no_of_philosophers * sizeof(t_fork));
	if (!data->forks)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->no_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i].fork_mutex, NULL);
		data->forks[i].fork_is_taken = 0;
		if (DEBUG)
			printf(YELLOW"Fork %d initialized\n"RESET, i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	destroy_forks(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->no_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i].fork_mutex);
		if (DEBUG)
			printf(YELLOW"Fork [%d] destroyed\n"RESET, i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}
