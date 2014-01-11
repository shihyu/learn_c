#include <stdio.h>

int main(int argc, char* argv[]) {
    int x, a, b;
    double c, d;
    a = 100;
    b = 50;
    c = 2.5;
    d = 5;
    x = (double)(a - b) + (c * d) / (double)b;
    printf("%lf\n", (a - b) + (c * d) / b);
    printf("x=%d\n", x);
    return 0;
}
