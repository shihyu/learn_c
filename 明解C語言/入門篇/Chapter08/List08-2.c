/*
整數的平方與浮點數的平方（函數巨集）
*/

#include  <stdio.h>

#define sqr(x)  ((x) * (x))             /* 求x的平方值 */

int main(void) {
    int     nx;
    double  dx;

    printf("請輸入一個整數：");
    scanf("%d",  &nx);
    printf("該數的平方為%d。\n", sqr(nx));

    printf("請輸入一個實數：");
    scanf("%lf", &dx);
    printf("該數的平方為%f。\n", sqr(dx));

    return (0);
}
