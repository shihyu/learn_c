#include <stdio.h>

int main()
{
    int a, b, c;
    printf("input a b c:");

    scanf("%d", &a);
    scanf("%x", &b);
    scanf("%o", &c);
    printf("a=%d, b=%d, c=%d\n", a, b, c);

    return 0;
}
