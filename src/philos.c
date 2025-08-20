#include "philosophers.h"

int	create_philos(t_philosopher **philos_ptr, pthread_mutex_t *forks, t_dinner dinner)
{
	t_philosopher	*philos;
	int				philos_count;
	int				i;

	philos_count = dinner.config.philos_count;
	philos = malloc(philos_count * sizeof(t_philosopher));
	if (!philos)
		return (-1);
	*philos_ptr = philos;
	i = 0;
	while (i < philos_count)
	{
		philos[i].index = i;
		philos[i].state = ALIVE;
		philos[i].config = dinner.config;
		philos[i].fork[LEFT] = &forks[i];
		philos[i].fork[RIGHT] = NULL;
		if (philos_count > 1)
			philos[i].fork[RIGHT] = &forks[(i + 1) % philos_count];
		philos[i].meal_last = dinner.config.start_ms;
		philos[i].meals_eaten = 0;
		printf("philo[%d] created!\n", i);
		i++;
	}
	return (1);
}

void	print_action(size_t index, e_action act)
{
	print_elapsed_ms();
	printf(" %zu ", index);
	if (act == LFORK || act == RFORK)
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
}
