/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:19:38 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:25:06 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool	is_full(t_philosopher *philo)
{
	if (philo->meals_eaten == philo->config.max_meals)
	{
		pthread_mutex_lock(&philo->state.lock);
		philo->state.val = DONE;
		pthread_mutex_unlock(&philo->state.lock);
		return (true);
	}
	return (false);
}

bool	sbdy_has_died(t_philosopher *philo)
{
	bool	res;

	pthread_mutex_lock(&philo->sbdy_died->lock);
	if (philo->sbdy_died->val == true)
		res = true;
	else
		res = false;
	pthread_mutex_unlock(&philo->sbdy_died->lock);
	return (res);
}

void	print_action(size_t index, t_action act)
{
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	print_elapsed_ms();
	printf(" %zu ", index);
	if (act == FORK)
		printf("has taken a fork");
	else if (act == DIE)
		printf("died");
	else if (act == EAT)
		printf("is eating");
	else if (act == SLEEP)
		printf("is sleeping");
	else if (act == THINK)
		printf("is thinking");
	printf("\n");
	pthread_mutex_unlock(&lock);
}
