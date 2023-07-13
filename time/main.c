#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void get_current_time()
{
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    printf("Current local time: %s", asctime(time_info));
}


static void get_seconds_since_1970()
{
    time_t t;
    t = time(NULL);
    printf("%ld\n", t);
}

int main()
{
    get_current_time();
    sleep(1);
    get_seconds_since_1970();
    return 0;
}