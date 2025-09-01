#include "../philosophers.h"

int init_threads(pthread_t **threads, t_philosopher *philos, t_dinner dinner)
{
	(void)philos;
	int	i;

	*threads = malloc(dinner.config.philos_count * sizeof(pthread_t));
	if (!threads)
		return (-1);
	i = 0;
	while (i < dinner.config.philos_count)
	{
		if (i % 2)
			pthread_create(&threads[0][i], NULL, odd_routine, &philos[i]);
		else
			pthread_create(&threads[0][i], NULL, even_routine, &philos[i]);
		i++;
	}
	return (1);
}

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
		if (philos_count > 1)
			philos[i].fork[RIGHT] = &forks[(i + 1) % philos_count];
		else
			philos[i].fork[RIGHT] = NULL;
		philos[i].meal_last = dinner.config.start_ms;
		philos[i].meals_eaten = 0;
		i++;
	}
	return (1);
}

void	join_free_threads(pthread_t *threads, int count)
{
	if (!threads)
		return ;
	while (count-- > 0)
		pthread_join(threads[count], NULL);
	free(threads);
}
