#include "philosophers.h"

void	*even_routine(void *data)
{
	(void)data;
	printf("even_routine\n");
	return (NULL);
}

void	*odd_routine(void *data)
{
	(void)data;
	printf("odd_routine\n");
	return (NULL);
}
