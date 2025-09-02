#include "../philosophers.h"

void	print_dinner(t_dinner dinner)
{
	printf("I N F O:\n");
	printf("elapsed time: ");
	print_elapsed_ms();
	printf(" ms\n");
	printf("\nconfig:\n");
	printf("philos count: %i\n", dinner.config.philos_count);
	printf("time to die: %i\n", dinner.config.time_to_die);
	printf("time to eat: %i\n", dinner.config.time_to_eat);
	printf("time to sleep: %i\n", dinner.config.time_to_sleep);
	if (dinner.config.max_meals != -1)
		printf("max meals: %i\n", dinner.config.max_meals);
	printf("\n\n");
}

void	print_philo(t_philosopher philo)
{
	printf("philo[%ld]: \n", philo.index);
	printf("fork[LEFT]: %p\n", philo.fork[LEFT]);
	printf("fork[RIGHT]: %p\n", philo.fork[RIGHT]);
	printf("meal last: %ld\n", philo.meal_last.val);
	printf("meals eaten: %d\n", philo.meals_eaten);
	printf("\n");
	printf("config:\n");
	if (philo.config.max_meals != -1)
		printf("max meals: %d\n", philo.config.max_meals);
	printf("start ms: %ld\n", philo.config.start_ms);
	printf("time to die: %d\n", philo.config.time_to_die);
	printf("time to eat: %d\n", philo.config.time_to_eat);
	printf("time to sleep: %d\n", philo.config.time_to_sleep);
}

void	print_philos(t_philosopher *philos)
{
	int	i;
	int	count;

	i = 0;
	count = philos[0].config.philos_count;
	while (i < count)
	{
		print_philo(philos[i]);
		printf("\n\n");
		i++;
	}
}
