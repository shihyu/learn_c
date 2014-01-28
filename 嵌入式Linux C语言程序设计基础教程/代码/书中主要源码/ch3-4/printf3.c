#include <stdio.h>

int main()
{
    int a = 1234;
    float f = 123.456;

    printf("%08d\n", a);
    printf("%010.2f\n", f);
    printf("%0+8d\n", a);
    printf("%0+10.2f\n", f);

    a = 123;
    printf("%o,%#o,%X,%#X\n", a, a, a, a);

    return 0;
}
