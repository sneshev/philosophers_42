#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
 
int     ft_gettime(struct timeval *tv);
long    get_elapsed_ms(struct timeval start, struct timeval curr);
void    print_elapsed_ms(struct timeval start, struct timeval curr);


bool    is_valid_input(int argc, char *argv[]);

typedef enum
{
    THINKING,
    EATING,
    SLEEPING,
    DEAD
}   e_state;

typedef struct
{
    size_t  index;
    e_state state;

}   t_philosopher;

typedef struct
{
    struct timeval  time_start;
    struct timeval  time_now;
} t_dinner_info;


#endif