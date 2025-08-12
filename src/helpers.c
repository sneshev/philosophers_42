#include "philosophers.h"

void	print_dinner(t_dinner dinner)
{
	printf("start time: %lu\n", dinner.time_start);
	printf("elapsed time: %lu\n", ft_gettime() - dinner.time_start);
	printf("\nconfig:\n");
	printf("philos count: %i\n", dinner.config.philos_count);
	printf("time to die: %i\n", dinner.config.time_to_die);
	printf("time to eat: %i\n", dinner.config.time_to_eat);
	printf("time to sleep: %i\n", dinner.config.time_to_sleep);
	if (dinner.config.max_meals != -1)
		printf("max meals: %i\n", dinner.config.max_meals);
}
