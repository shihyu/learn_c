#include <stdio.h>
#include <string.h>
#define N 64

union gy
{
    char a;
    short b;
    int c;
};

int main()
{
    union gy t;

    t.c = 0x12345678;

    printf("sizeof(union gy) = %d\n", sizeof(union gy));

    printf("%p %p %p\n", &t.a, &t.b, &t.c);
    printf("%#x %#x %#x\n", t.a, t.b, t.c);


    return 0;
}
