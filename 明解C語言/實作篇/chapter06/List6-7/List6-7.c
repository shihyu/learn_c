/*
    求出3次方的值(函式原型宣告)
*/

#include  <stdio.h>

double pow(double, double); /* 函式原型宣告 */

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的3次方為%.3f。\n", pow(x, 3));

    system("PAUSE");
    return (0);
}
