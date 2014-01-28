#include <stdio.h>

union A 
{
    struct 
    {
        unsigned int a: 2;
        unsigned int b: 4;
        unsigned int c: 2;
    }t;
    char m; 
}data;

int main()
{
    data.t.a = 2;
    data.t.b = 5;
    data.t.c = 1;


    printf("%d\n", data.m);

    return 0;
}
