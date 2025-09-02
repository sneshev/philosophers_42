#include "../philosophers.h"

static void	take_fork(t_philosopher *philo, int side, bool fork_taken)
{
	pthread_mutex_t **fork;

	fork = philo->fork;
	while (pthread_mutex_trylock(fork[side]) != 0)
	{
		usleep(500);
		if (has_starved(philo) || sbdy_died(philo))
		{
			if (fork_taken && side == LEFT)
				pthread_mutex_unlock(fork[RIGHT]);
			else if (fork_taken && side == RIGHT)
				pthread_mutex_unlock(fork[LEFT]);
			pthread_exit(NULL);
		}
	}
	print_action(philo->index, FORK);
}

static void	nom_nom_nom(t_philosopher *philo)
{
	long	start_ms;
	long	time_to_eat;

	if (has_starved(philo) || sbdy_died(philo))
		return ; // to unlock mutexes
	print_action(philo->index, EAT);
	start_ms = get_elapsed_ms();
	time_to_eat = philo->config.time_to_eat;
	while (get_elapsed_ms() < start_ms + time_to_eat)
	{
		usleep(500);
		if (has_starved(philo) || sbdy_died(philo))
			return ; // to unlock mutexes
	}
}

static void	eat_odd(t_philosopher *philo)
{
	take_fork(philo, LEFT, 0);
	take_fork(philo, RIGHT, 1);
	nom_nom_nom(philo);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->fork[LEFT]);
	pthread_mutex_unlock(philo->fork[RIGHT]);
}

static void	eat_even(t_philosopher *philo)
{
	take_fork(philo, RIGHT, 0);
	take_fork(philo, LEFT, 1);
	nom_nom_nom(philo);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->fork[RIGHT]);
	pthread_mutex_unlock(philo->fork[LEFT]);
}

void	eat(t_philosopher *philo)
{
	if (philo->index % 2) // odd
		eat_odd(philo);
	else
		eat_even(philo);
	if (has_starved(philo) || sbdy_died(philo))
		pthread_exit(NULL);
	else if (philo->meals_eaten == philo->config.max_meals)
	{
		philo->state = DONE; // add mutex ! ! !
		pthread_exit(NULL);
	}
}
