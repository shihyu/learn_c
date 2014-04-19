#include <stdio.h>     
#include <stdlib.h>
#include <string.h>
#include <math.h>

int my_atoi(char *s)
{
    int i;
    int len = strlen(s) - 1;
    int sum = 0;


    for (i = 0; i < len; ++i)
    {
        sum += (s[i] - '0') * pow(10, len-1);
    }

    return sum;
}

int main() {
    int i;
    char buffer[256];
    printf("Enter a number: \n");
    fgets (buffer, 256, stdin);
    i = my_atoi(buffer);
    printf("The value entered is %d.", i);
    return 0;
}
