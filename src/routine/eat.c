#include "../philosophers.h"

static int	take_fork(t_philosopher *philo, int side)
{
	pthread_mutex_t	*fork;

	if (has_starved(philo) || sbdy_died(*philo))
		return (-1);
	fork = philo->fork[side];	
	pthread_mutex_lock(fork);
	printf("%ld locked %p\n", philo->index, fork);
	if (has_starved(philo) || sbdy_died(*philo))
	{
		pthread_mutex_unlock(fork);
		return (-1);
	}
	print_action(philo->index, FORK);
	return (1);
}

static void	nom_nom_nom(t_philosopher *philo)
{
	long	start_ms;
	long	time_to_eat;

	if (has_starved(philo) || sbdy_died(*philo))
		return ; // to unlock mutexes
	print_action(philo->index, EAT);
	pthread_mutex_lock(&philo->meal_last.lock);
	philo->meal_last.val = get_elapsed_ms();
	pthread_mutex_unlock(&philo->meal_last.lock);
	
	start_ms = get_elapsed_ms();
	time_to_eat = philo->config.time_to_eat;
	while (get_elapsed_ms() < start_ms + time_to_eat)
	{
		usleep(500);
		if (has_starved(philo) || sbdy_died(*philo))
			return ; // to unlock mutexes
	}
	philo->meals_eaten++;
}

static void	eat_odd(t_philosopher *philo)
{
	if (take_fork(philo, LEFT) == -1)
		return ;
	if (take_fork(philo, RIGHT) == -1)
	{
		pthread_mutex_unlock(philo->fork[LEFT]);
		return ;
	}
	nom_nom_nom(philo);
	pthread_mutex_unlock(philo->fork[LEFT]);
	printf("%ld unlocked %p\n", philo->index, philo->fork[LEFT]);
	pthread_mutex_unlock(philo->fork[RIGHT]);
	printf("%ld unlocked %p\n", philo->index, philo->fork[RIGHT]);
}

static void	eat_even(t_philosopher *philo)
{
	if (take_fork(philo, RIGHT) == -1)
		return;
	if (take_fork(philo, LEFT) == -1)
	{
		pthread_mutex_unlock(philo->fork[RIGHT]);
		return;
	}
	nom_nom_nom(philo);
	pthread_mutex_unlock(philo->fork[RIGHT]);
	pthread_mutex_unlock(philo->fork[LEFT]);
}

void	eat(t_philosopher *philo)
{
	if (philo->index % 2) // odd
		eat_odd(philo);
	else
		eat_even(philo);	
}
