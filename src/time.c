#include "philosophers.h"

// elapsed time in milliseconds
long    get_elapsed_ms(struct timeval start, struct timeval curr)
{
    long    secs;
    long    millisecs;
    long    microsecs;

    secs = curr.tv_sec - start.tv_sec;
    microsecs = curr.tv_usec - start.tv_usec;
    if (microsecs < 0)
    {
        secs -= 1;
        microsecs += 1000000;
    }
    millisecs = secs * 1000;
    millisecs += microsecs / 1000;
    return (millisecs);
}

void    print_elapsed_ms(struct timeval start, struct timeval curr)
{
    printf("%lu", get_elapsed_ms(start, curr));
}

int ft_gettime(struct timeval *tv)
{
    return (gettimeofday(tv, NULL));
}