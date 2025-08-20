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
	return (1);
}

// int main()
int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	t_philosopher	*philos;
	t_dinner		dinner;
	t_config		config;
	// int argc = 6;
	// char *argv[argc];
	// argv[0] = "./philosophers";
	// argv[1] = "1";
	// argv[2] = "200";
	// argv[3] = "60";
	// argv[4] = "75";
	// argv[5] = "4";

	if (!is_valid_input(argc, argv))
		return (1);
	if (prepare_dinner(&dinner, argc, argv) == -1)
		return (1);
	config = dinner.config;
	if (create_forks(&forks, config.philos_count) == -1)
		return (1); // dont have to free_dinner() yet
	if (create_philos(&philos, forks, dinner) == -1)
		return (destroy_forks(forks, config.philos_count), 1);
	//...

	print_philos(philos);
	
	ft_sleep(619, MILLISEC);

	t_philosopher philo = philos[0]; 
	print_action(philo.index, LFORK);
	print_action(philo.index, RFORK);
	print_action(philo.index, EAT);
	print_action(philo.index, SLEEP);
	print_action(philo.index, THINK);
	print_action(philo.index, DIE);

	destroy_forks(forks, config.philos_count);
	free(philos);
}

/*
	.if there is one philo left fork and right fork is same

	.add gitignore
*/