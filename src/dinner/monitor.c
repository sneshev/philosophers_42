/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:20:41 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:20:54 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static bool	has_died(t_philosopher *philo)
{
	long	elapsed_ms;
	long	to_die_ms;
	bool	result;

	elapsed_ms = get_elapsed_ms();
	to_die_ms = philo->config.time_to_die;
	pthread_mutex_lock(&philo->meal_last.lock);
	if (elapsed_ms - philo->meal_last.val >= to_die_ms)
		result = true;
	else
		result = false;
	pthread_mutex_unlock(&philo->meal_last.lock);
	return (result);
}

static bool	philos_are_full(t_philosopher *philos, int philos_count)
{
	int	i;

	i = 0;
	while (i < philos_count)
	{
		pthread_mutex_lock(&philos[i].state.lock);
		if (philos[i].state.val != DONE)
		{
			pthread_mutex_unlock(&philos[i].state.lock);
			return (false);
		}
		pthread_mutex_unlock(&philos[i].state.lock);
		i++;
	}
	return (true);
}

void	monitor(t_dinner *dinner, t_philosopher *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < dinner->config.philos_count)
		{
			if (has_died(&philos[i]))
			{
				pthread_mutex_lock(&dinner->sbdy_died.lock);
				dinner->sbdy_died.val = true;
				pthread_mutex_unlock(&dinner->sbdy_died.lock);
				print_action(philos[i].index, DIE);
				return ;
			}
			else if (philos_are_full(philos, dinner->config.philos_count))
				return ;
			i++;
		}
		usleep(500);
	}
}
