#include "../philosophers.h"

bool	has_died(t_philosopher *philo)
{
	long	elapsed_ms;
	long	to_die_ms;
	bool	result;

	elapsed_ms = get_elapsed_ms();
	to_die_ms = philo->config.time_to_die;
	pthread_mutex_lock(&philo->meal_last.lock);
	if (elapsed_ms - philo->meal_last.val >= to_die_ms)
		result = true;
	else
		result = false;
	pthread_mutex_unlock(&philo->meal_last.lock);
	return (result);
}
// 400 - 200

void	monitor(t_dinner *dinner, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (1)
	{
		while(i < dinner->config.philos_count)
		{
			i++;
		}
	}
}