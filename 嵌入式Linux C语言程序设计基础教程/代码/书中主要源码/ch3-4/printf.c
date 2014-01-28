#include <stdio.h>

int main()
{
    int a = 1234;
    float f = 123.456;
    char ch = 'a';
    char s[] = "Hello world!";

    printf("%8d,%2d\n", a, a);
    printf("%f,%8f,%8.1f,%.2f\n", f, f, f, f);
    printf("%3c\n", ch);
    printf("%s\n%15s\n%10.5s\n%2.5s\n%.3s\n", s, s, s, s, s);

    return 0;
}
