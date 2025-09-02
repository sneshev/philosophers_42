#include "../philosophers.h"

void	print_action(size_t index, e_action act)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	print_elapsed_ms();
	printf(" %zu ", index);
	if (act == FORK)
		printf("has taken a fork");
	else if (act == DIE)
		printf("died");
	else if (act == EAT)
		printf("is eating");
	else if (act == SLEEP)
		printf("is sleeping");
	else if (act == THINK)
		printf("is thinking");
	printf("\n");
	pthread_mutex_unlock(&lock);
}
