#include "philosophers.h"

void	destroy_forks(pthread_mutex_t *forks, int amount)
{
	if (!forks)
		return ;
	while (amount >= 0)
	{
		pthread_mutex_destroy(&forks[amount]);
		amount--;
	}
	free(forks);
}

int	create_forks(pthread_mutex_t **forks_ptr, int amount)
{
	pthread_mutex_t *forks;
	int i;

	forks = malloc(amount * sizeof(pthread_mutex_t));
	if (!forks)
		return (-1); // dont have to free_dinner() yet
	*forks_ptr = forks;
	i = 0;
	while (i < amount)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (destroy_forks(forks, i - 1), -1);
		i++;
	}
	return (1);
}
