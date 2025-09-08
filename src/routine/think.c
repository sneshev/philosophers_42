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
	printf("(%ld)meal_last      : %ld\n", philo->index, philo->meal_last.val);
	printf("(%ld)elapsed ms     : %ld\n", philo->index, get_elapsed_ms());
	printf("(%ld)since last meal: %d\n", philo->index, ms_since_last_meal);
	printf("(%ld)to_die_ms    : %d\n", philo->index, ms_to_die);
	printf("(%ld)to_think_ms    : %d\n", philo->index, to_think_ms);
	perform_action(philo, to_think_ms);
}