#include "../philosophers.h"

bool	has_starved(t_philosopher *philo)
{
	long	elapsed_ms;
	long	last_meal;
	long	time_to_die;

	elapsed_ms = get_elapsed_ms;
	last_meal = philo->meal_last;
	time_to_die = philo->config.time_to_die;
	if (elapsed_ms - last_meal < time_to_die)
		return (false);
	else
	{
		philo->state = DEAD; // add mutex ! ! !
		return (true);
	}
}

void	*even_routine(void *philo_ptr)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)philo_ptr;
	while (1)
	{
		eat(&philo);
		sleeep(&philo);
		print_action(philo.index, THINK);
	}
	return (NULL);
}

void	*odd_routine(void *philo_ptr)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)philo_ptr;
	printf("philo %ld : odd_routine\n", philo.index);
	return (NULL);
}
