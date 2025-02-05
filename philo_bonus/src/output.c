/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:33:15 by dmlasko           #+#    #+#             */
/*   Updated: 2025/02/05 15:47:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(char *str, int error_code)
{
	printf(RED"%s"RST, str);
	return (error_code);
}

void	write_status(t_data *data, t_philosopher *philo, t_status status)
{
	long	runtime;

	sem_wait(data->sem_print);
	if (DEBUG)
		return (write_status_debug(data, philo, status));
	runtime = get_sim_runtime_ms(data);
	if (TAKEN_LEFT_FORK == status)
		printf(MSG_LEFT_FORK, runtime, philo->id);
	else if (TAKEN_RIGHT_FORK == status)
		printf(MSG_RIGHT_FORK, runtime, philo->id);
	else if (EATING == status)
		printf(MSG_EAT, runtime, philo->id);
	else if (SLEEPING == status)
		printf(MSG_SLEEP, runtime, philo->id);
	else if (THINKING == status)
		printf(MSG_THINK, runtime, philo->id);
	else if (DIED == status)
	{
		printf(MSG_DIED, runtime, philo->id);
		exit (0);
	}
	sem_post(data->sem_print);
}
