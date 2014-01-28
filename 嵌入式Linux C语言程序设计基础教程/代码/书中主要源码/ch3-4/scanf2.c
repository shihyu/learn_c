#include <stdio.h>

int main()
{
    int yy, mm, dd;
    int a;
    float c;

    printf("input year month day:");
    scanf("%4d%2d%2d", &yy, &mm, &dd);
    printf("%d-%d-%d\n", yy, mm, dd);

    printf("input  int float:");
    scanf("%3d%*4d%f", &a, &c);
    printf("a=%d, c=%f\n", a, c);

    return 0;
}
