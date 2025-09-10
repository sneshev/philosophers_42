#include "philosophers.h"

// init dinner struct and static var function
int	prepare_dinner(t_dinner *dinner, int argc, char *argv[])
{
	dinner->config.start_ms = get_elapsed_ms();
	if (dinner->config.start_ms == -1)
		return (-1);
	dinner->config.philos_count = ft_atoi(argv[1]);
	dinner->config.time_to_die = ft_atoi(argv[2]);
	dinner->config.time_to_eat = ft_atoi(argv[3]);
	dinner->config.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		dinner->config.max_meals = ft_atoi(argv[5]);
	else
		dinner->config.max_meals = -1;
	pthread_mutex_init(&dinner->sbdy_died.lock, NULL);
	dinner->sbdy_died.val = false;
	return (1);
}

void	end_program(t_dinner *dinner, pthread_mutex_t *forks, t_philosopher *philos, pthread_t *threads)
{
	int i;

	if (threads)
		join_free_threads(threads, dinner->config.philos_count);
	if (philos)
	{
		i = 0;
		while (i < dinner->config.philos_count)
		{
			pthread_mutex_destroy(&philos[i].state.lock);
			pthread_mutex_destroy(&philos[i].meal_last.lock);
			i++;
		}
		free(philos);
	}
	if (forks)
		destroy_forks(forks, dinner->config.philos_count);
	pthread_mutex_destroy(&dinner->sbdy_died.lock);
}

// int main()
int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philosopher	*philos;
	t_dinner		dinner;
	t_config		config;
	// int argc = 6;
	// char *argv[argc];
	// argv[0] = "./philosophers";
	// argv[1] = "5";
	// argv[2] = "500";
	// argv[3] = "111";
	// argv[4] = "222";
	// argv[5] = "4";

	if (!is_valid_input(argc, argv))
		return (1);
	if (prepare_dinner(&dinner, argc, argv) == -1)
		return (1);
	config = dinner.config;
	if (create_forks(&forks, config.philos_count) == -1)
		return (end_program(&dinner, NULL, NULL, NULL), 1);
	if (create_philos(&philos, forks, &dinner) == -1)
		return (end_program(&dinner, forks, NULL, NULL), 1);
	if (init_threads(&threads, philos, dinner) == -1)
		return (end_program(&dinner, forks, philos, NULL), 1);
	monitor(&dinner, philos);
	end_program(&dinner, forks, philos, threads);
}

/*
	.if there is one philo left fork and right fork is same

*/