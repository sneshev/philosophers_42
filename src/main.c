#include "philosophers.h"

int prepare_dinner(t_dinner *dinner)
{
    if (get_start_time(dinner) < 0)
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

    // sleep(2);
    usleep(3000);
    get_curr_time(&dinner);
    print_elapsed_ms(dinner.time_start, dinner.time_now);
    printf("\n");

    usleep(30000);
    get_curr_time(&dinner);
    print_elapsed_ms(dinner.time_start, dinner.time_now);
    printf("\n");
    usleep(1010100);
    get_curr_time(&dinner);
    print_elapsed_ms(dinner.time_start, dinner.time_now);
    printf("\n");

    printf("ez\n");
}
