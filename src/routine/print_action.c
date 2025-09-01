#include "../philosophers.h"

void	print_action(size_t index, e_action act)
{
	print_elapsed_ms();
	printf(" %zu ", index);
	if (act == LFORK || act == RFORK)
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
}