/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:11 by stefuntu          #+#    #+#             */
/*   Updated: 2025/09/10 20:17:27 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// malloc for and init fork mutexes
int	create_forks(pthread_mutex_t **forks_ptr, int amount)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(amount * sizeof(pthread_mutex_t));
	if (!forks)
		return (-1);
	*forks_ptr = forks;
	i = 0;
	while (i < amount)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (destroy_forks(forks, i), -1);
		i++;
	}
	return (1);
}

// amount starts from 1 (if 10 forks, amount = 10)
void	destroy_forks(pthread_mutex_t *forks, int amount)
{
	if (!forks)
		return ;
	while (amount-- > 0)
		pthread_mutex_destroy(&forks[amount]);
	free(forks);
}
