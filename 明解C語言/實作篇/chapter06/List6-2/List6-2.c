/*
    求出平方值(將main函式放在前方)
*/

#include  <stdio.h>

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的平方為%.3f。\n", sqr(x));      /* 警告 */

    system("PAUSE");
    return (0);
}

/*--- 求出平方值 ---*/
double sqr(double x) {                                  /* 錯誤 */
    return (x * x);
}


