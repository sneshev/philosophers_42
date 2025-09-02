#include "../philosophers.h"

void	sleeep(t_philosopher *philo)
{
	if (has_starved(philo) || sbdy_died(*philo))
		return ;
	print_action(philo->index, SLEEP);
	perform_action(philo, philo->config.time_to_sleep);
}

/*
	start_ms      = 0
	time_to_sleep = 100

	start_ms + time_to_sleep = 100;

	get_elapsed_time = 0;
*/