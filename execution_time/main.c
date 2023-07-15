/**
 * 
 * C program to find execution time and clock time.
 * 
 * Credit to:  https://code-vault.net/lesson/7475a60f972f545c64ae6e5ab80007af
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NANO  1000000000.0
int main(int argc , char **argv){
    struct  timespec start;
    struct  timespec start2;

    timespec_get(&start, TIME_UTC);
    timespec_get(&start2, TIME_UTC);

    sleep(2);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start2);

    for (size_t i = 0; i < 10000000; i++)
    {
        i%2;
    }
    

    struct  timespec end;
    timespec_get(&end, TIME_UTC);

    struct timespec end2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end2);

    double diff_time= (end.tv_sec - start.tv_sec ) + (end.tv_nsec - start.tv_nsec)/NANO;
    double time_spent2 = (end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / NANO;

    printf("Time taken program to execute  %lf\n", diff_time);
    
    printf("Time taken program to execute  %lf\n", time_spent2);

    return 0;
}