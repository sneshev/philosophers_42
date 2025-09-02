#include "../philosophers.h"

void	sleeep(t_philosopher *philo)
{
	long	start_ms;
	long	time_to_sleep;

	if (has_starved(philo) || sbdy_died(*philo))
		return ;
	print_action(philo->index, SLEEP);
	start_ms = get_elapsed_ms();
	time_to_sleep = philo->config.time_to_sleep;
	while (get_elapsed_ms() < start_ms + time_to_sleep)
	{
		usleep(500);
		if (has_starved(philo) || sbdy_died(*philo))
			return ;
	}
}

/*
	start_ms      = 0
	time_to_sleep = 100

	start_ms + time_to_sleep = 100;

	get_elapsed_time = 0;
*/