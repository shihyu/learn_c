/*
    求出平方值(將main函式放在後方)
*/

#include  <stdio.h>

/*--- 求出平方值 ---*/
double sqr(double x) {
    return (x * x);
}

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的平方為%.3f。\n", sqr(x));

    system("PAUSE");
    return (0);
}
