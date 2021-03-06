#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
   
    if (argc != 2)
    {
        fprintf(2, "Usage: sleep [time]\n");
        exit(1);
    }
    int time = atoi(argv[1]);
    if ( time < 0)
    {
        printf("can't sleep %s\n", time);
        exit(1);
    }

    sleep(time);


    exit(0);
}
