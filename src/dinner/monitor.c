#include "../philosophers.h"

static bool	has_died(t_philosopher philo)
{
	long	elapsed_ms;
	long	to_die_ms;
	bool	result;

	elapsed_ms = get_elapsed_ms();
	to_die_ms = philo.config.time_to_die;
	pthread_mutex_lock(&philo.meal_last.lock);
	if (elapsed_ms - philo.meal_last.val >= to_die_ms)
		result = true;
	else
		result = false;
	pthread_mutex_unlock(&philo.meal_last.lock);
	return (result);
}
// 400 - 200

void	monitor(t_dinner *dinner, t_philosopher *philos)
{
	int	i;

	while (1)
	{
		i = 0;
		while(i < dinner->config.philos_count)
		{
			if (has_died(philos[i]))
			{
				pthread_mutex_lock(&dinner->sbdy_died.lock);
				dinner->sbdy_died.val = true;
				pthread_mutex_unlock(&dinner->sbdy_died.lock);
				print_action(philos[i].index, DIE);
				return ;
			}
			i++;
		}
		usleep(500);
	}
}