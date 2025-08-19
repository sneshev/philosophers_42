#include "philosophers.h"


int	create_philos(t_philosopher **philos_ptr, pthread_mutex_t *forks, t_dinner dinner)
{
	t_philosopher	*philos;
	t_config		config;
	int				philos_count;
	int				i;

	config = dinner.config;
	philos_count = config.philos_count;
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
		philos[i].fork[RIGHT] = &forks[(i + 1) % philos_count];
		philos[i].meal_last = config.start_ms;
		philos[i].meals_eaten = 0;
		printf("philo[%d] created!\n", i);
		i++;
	}
	return (1);
}
