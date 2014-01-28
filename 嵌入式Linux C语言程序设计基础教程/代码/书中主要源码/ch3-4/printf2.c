#include <stdio.h>

int main()
{
    int a = 1234;
    float f = 123.456;
    char s[] = "Hello world!";

    printf("%8d,%-8d\n", a, a);
    printf("%10.2f,%-10.1f\n", f, f);
    printf("%10.5s,%-10.3s\n", s, s);

    return 0;
}
