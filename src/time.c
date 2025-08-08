#include "philosophers.h"

// elapsed time in milliseconds
long    get_elapsed_ms(t_dinner dinner)
{
    return (dinner.time_now - dinner.time_start);
}

void    print_elapsed_ms(t_dinner dinner)
{
    long    ms;

    ms = get_elapsed_ms(dinner);
    if (ms < 1000)
        printf("0");
    if (ms < 100)
        printf("0");
    if (ms < 10)
        printf("0");
    printf("%lu", ms);
}

long    ft_gettime(void)
{
    struct timeval  tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (-1);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
