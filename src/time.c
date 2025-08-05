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
    long    millisecs;

    millisecs = get_elapsed_ms(start, curr);
    if (millisecs < 1000)
        printf("0");
    if (millisecs < 100)
        printf("0");
    if (millisecs < 10)
        printf("0");
    printf("%lu", millisecs);
}

int get_start_time(t_dinner *dinner)
{
    return (gettimeofday(&(dinner->time_start), NULL));
}

int get_curr_time(t_dinner *dinner)
{
    return (gettimeofday(&(dinner->time_now), NULL));
}