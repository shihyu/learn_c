/*
整數的平方與浮點數的平方（函式）
*/

#include  <stdio.h>

/*---int型態整數的平方值---*/
int sqr_int(int x) {
    return (x * x);
}

/*---double型態浮點數的平方值---*/
double sqr_double(double x) {
    return (x * x);
}

int main(void) {
    int     nx;
    double  dx;

    printf("請輸入一個整數：");
    scanf("%d",  &nx);
    printf("該數的平方為%d。\n", sqr_int(nx));

    printf("請輸入一個實數：");
    scanf("%lf", &dx);
    printf("該數的平方為%f。\n", sqr_double(dx));

    return (0);
}
