#include "../philosophers.h"

void	*even_routine(void *philo_ptr)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)philo_ptr;
	printf("philo %ld : even_routine\n",	 philo.index);
	return (NULL);
}

void	*odd_routine(void *philo_ptr)
{
	t_philosopher	philo;

	philo = *(t_philosopher *)philo_ptr;
	printf("philo %ld : odd_routine\n", philo.index);
	return (NULL);
}
