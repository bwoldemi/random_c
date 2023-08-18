
#include <stdio.h>  
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

    int main()
{
    int iSecret, iGuess;

    /* initialize random seed: */
    srand(time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n", rand());      
    }
    return 0;
}