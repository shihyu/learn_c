#include <stdio.h>

void count(int val)
{
    if (val > 1)
        count(val - 1);
    printf("OK:%d\n", val);
}

int main()
{
    int n = 10;

    count(n);

    return 0;
}
