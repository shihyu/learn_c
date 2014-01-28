#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = true;
    int x = 5;
    
    a = x > 3;
    if (a)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
