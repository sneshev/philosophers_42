#include "philosophers.h"

static long	ft_gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// elapsed time in milliseconds
long	get_elapsed_ms(void)
{
	static long	time_start = -2;
	long		time_now;

	if (time_start == -2)
	{
		time_start = ft_gettime();
		if (time_start == -1)
		{
			write(2, "error getting time\n", 19);
			return (time_start);
		}
		return (time_start);
	}
	time_now = ft_gettime();
	if (time_now == -1)
	{
		write(2, "error getting time\n", 19);
		return (-1);
	}
	return (time_now - time_start);
}

void	print_elapsed_ms(void)
{
	long	ms;

	ms = get_elapsed_ms();
	if (ms < 1000)
		printf("0");
	if (ms < 100)
		printf("0");
	if (ms < 10)
		printf("0");
	printf("%lu", ms);
}

void	ft_sleep(long time_to_sleep, e_time type)
{
	long	start;

	if (type == MICROSEC)
		time_to_sleep /= 1000;
	if (type == SEC)
		time_to_sleep *= 1000;
	start = ft_gettime();
	while (ft_gettime() - start < time_to_sleep)
		usleep(500);
}
