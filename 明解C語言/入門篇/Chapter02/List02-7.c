/*
  計算兩個實數之和、差、乘積與商再輸出
*/

#include <stdio.h>

int main(void) {
    double vx, vy;         /* 浮點數 */

    puts("請輸入兩個數值：");
    printf("實數vx：");
    scanf("%lf", &vx);
    printf("實數vy：");
    scanf("%lf", &vy);

    printf("vx + vy = %f\n", vx + vy);
    printf("vx - vy = %f\n", vx - vy);
    printf("vx * vy = %f\n", vx * vy);
    printf("vx / vy = %f\n", vx / vy);

    return (0);
}
