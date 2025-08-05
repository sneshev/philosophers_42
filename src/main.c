#include "philosophers.h"




// int main()
int main(int argc, char *argv[])
{
    // int argc = 5;
    // char *argv[argc];
    // argv[0] = "./philosophers";
    // argv[1] = "1234567890";
    // argv[2] = "2148000000";
    // argv[3] = "21";
    // argv[4] = "212320";

    if (!is_valid_input(argc, argv))
        return (1);
    write(1, "ez\n", 3);
}