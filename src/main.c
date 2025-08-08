#include "philosophers.h"

int prepare_dinner(t_dinner *dinner)
{
    dinner->time_start = ft_gettime();
    if (dinner->time_start == -1)
        return (-1);
    return (1);
}

// int main()
int main(int argc, char *argv[])
{
    t_dinner   dinner;
    // int argc = 5;
    // char *argv[argc];
    // argv[0] = "./philosophers";
    // argv[1] = "1234567890";
    // argv[2] = "2148000000";
    // argv[3] = "21";
    // argv[4] = "212320";

    if (!is_valid_input(argc, argv))
        return (1);
    if (prepare_dinner(&dinner) == -1)
        return (1);
    usleep(1600);
    dinner.time_now = ft_gettime();
    print_elapsed_ms(dinner);
    printf("ez\n");
}
