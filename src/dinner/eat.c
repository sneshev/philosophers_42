/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:20:03 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:20:12 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	take_fork(t_philosopher *philo, int side)
{
	if (sbdy_has_died(philo))
		return (-1);
	pthread_mutex_lock(philo->fork[side]);
	if (sbdy_has_died(philo))
	{
		pthread_mutex_unlock(philo->fork[side]);
		return (-1);
	}
	print_action(philo->index, FORK);
	return (1);
}

static void	nom_nom(t_philosopher *philo)
{
	if (!sbdy_has_died(philo))
	{
		print_action(philo->index, EAT);
		pthread_mutex_lock(&philo->meal_last.lock);
		philo->meal_last.val = get_elapsed_ms();
		pthread_mutex_unlock(&philo->meal_last.lock);
		philo->meals_eaten++;
		perform_action(philo, philo->config.time_to_eat);
	}
}

static void	do_eating_cycle(t_philosopher *philo, int side, int opposite)
{
	if (take_fork(philo, side) == -1)
		return ;
	if (take_fork(philo, opposite) == -1)
	{
		pthread_mutex_unlock(philo->fork[side]);
		return ;
	}
	nom_nom(philo);
	pthread_mutex_unlock(philo->fork[LEFT]);
	pthread_mutex_unlock(philo->fork[RIGHT]);
}

void	eat(t_philosopher *philo)
{
	if (philo->index % 2)
		do_eating_cycle(philo, LEFT, RIGHT);
	else
		do_eating_cycle(philo, RIGHT, LEFT);
	if (philo->meals_eaten == philo->config.max_meals)
	{
		pthread_mutex_lock(&philo->state.lock);
		philo->state.val = DONE;
		pthread_mutex_unlock(&philo->state.lock);
	}
}
