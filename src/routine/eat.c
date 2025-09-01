#include "../philosophers.h"

static void	eat_odd(t_philosopher *philo)
{
	(void)philo;
}

static void	eat_even(t_philosopher *philo)
{
	(void)philo;
}

void	eat(t_philosopher *philo)
{
	if (philo->index % 2) // odd
		eat_odd(philo);
	else
		eat_even(philo);
	if (philo->meals_eaten == philo->config.max_meals)
	{
		philo->state = DONE; // add mutex ! ! !
		pthread_exit(NULL);
	}
}
