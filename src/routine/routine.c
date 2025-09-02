#include "../philosophers.h"

/*
	only checks if the specific philosopher has died
	must check if any philosopher has died ! !
*/
bool	has_starved(t_philosopher *philo)
{
	long	elapsed_ms;
	long	last_meal;
	long	time_to_die;

	elapsed_ms = get_elapsed_ms();
	last_meal = philo->meal_last.val;
	time_to_die = philo->config.time_to_die;
	if (elapsed_ms - last_meal < time_to_die)
		return (false);
	else
	{
		print_action(philo->index, DIE);
		pthread_mutex_lock(&philo->state.lock);
		philo->state.val = DEAD;
		pthread_mutex_unlock(&philo->state.lock);
		return (true);
	}
}

void	perform_action(t_philosopher *philo, long ms_to_pass)
{
	long	finish_time;

	finish_time = get_elapsed_ms() + ms_to_pass;
	while (get_elapsed_ms() < finish_time)
	{
		usleep(500);
		if (has_starved(philo) || sbdy_died(*philo))
			return ;
	}
}

void	*routine(void *philo_ptr)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)philo_ptr;
	while (philo.state.val == ALIVE && !sbdy_died(philo))
	{
		eat(&philo);
		if (philo.state.val == DEAD || is_full(&philo) || sbdy_died(philo))
			return (NULL);
		sleeep(&philo);
		if (philo.state.val == DEAD || sbdy_died(philo))
			return (NULL);
		print_action(philo.index, THINK);
	}
	return (NULL);
}
