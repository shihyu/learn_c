#include <stdio.h>

int main()
{
    int a;
    char b;
    float c;
    printf("input three elements:");

    scanf("%d%c%f", &a, &b, &c);
    printf("a=%d, b=%c, c=%f\n", a, b, c);

    return 0;
}
