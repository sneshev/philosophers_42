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
    long    time_start;
    long    time_now;
} t_dinner;


long    ft_gettime(void);
void    print_elapsed_ms(t_dinner dinner);
long    get_elapsed_ms(t_dinner dinner);

#endif