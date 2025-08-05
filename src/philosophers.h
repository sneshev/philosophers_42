#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
 


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
    struct timeval  time;
} t_dinner_info;


#endif