/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:20:28 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:20:28 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	think(t_philosopher *philo)
{
	int	ms_since_last_meal;
	int	ms_to_die;
	int	to_think_ms;

	ms_to_die = philo->config.time_to_die;
	pthread_mutex_lock(&philo->meal_last.lock);
	ms_since_last_meal = get_elapsed_ms() - philo->meal_last.val;
	pthread_mutex_unlock(&philo->meal_last.lock);
	print_action(philo->index, THINK);
	to_think_ms = (ms_to_die - ms_since_last_meal) / 7;
	perform_action(philo, to_think_ms);
}
