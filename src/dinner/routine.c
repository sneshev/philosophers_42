/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:21:00 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:21:14 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	has_starved(t_philosopher *philo)
{
	long	elapsed_ms;
	long	last_meal;
	long	time_to_die;

	elapsed_ms = get_elapsed_ms();
	last_meal = philo->meal_last.val;
	time_to_die = philo->config.time_to_die;
	if (elapsed_ms - last_meal < time_to_die)
		return (false);
	else
	{
		print_action(philo->index, DIE);
		pthread_mutex_lock(&philo->state.lock);
		philo->state.val = DEAD;
		pthread_mutex_unlock(&philo->state.lock);
		return (true);
	}
}

void	perform_action(t_philosopher *philo, long ms_to_pass)
{
	long	finish_time;

	finish_time = get_elapsed_ms() + ms_to_pass;
	while (get_elapsed_ms() < finish_time)
	{
		usleep(500);
		if (sbdy_has_died(philo))
			return ;
	}
}

void	*routine(void *philo_ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_ptr;
	while (1)
	{
		eat(philo);
		if (is_full(philo) || sbdy_has_died(philo))
			return (NULL);
		sleeep(philo);
		if (sbdy_has_died(philo))
			return (NULL);
		think(philo);
	}
	return (NULL);
}
