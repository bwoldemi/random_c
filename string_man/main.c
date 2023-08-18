#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **args)
{
    char apn_name[] = "internet.ims";

    char apn[10];
    for (size_t i = 0; i <= strlen(apn_name); i++)
    {
        if (apn_name[i] != '.')
        {
            printf("%c\n", apn_name[i]);
        }
    }

    return 0;
}