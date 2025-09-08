#include "../philosophers.h"

void	think(t_philosopher *philo)
{
	int	ms_since_last_meal;
	int	ms_to_die;
	int	to_think_ms;

	ms_to_die = philo->config.time_to_die;
	ms_since_last_meal = get_elapsed_ms() - philo->meal_last.val;
	print_action(philo->index, THINK);
	to_think_ms = (ms_to_die - ms_since_last_meal) / 2;
	perform_action(philo, to_think_ms);
}