/*
  輸出兩個整數數值的和、差、乘積與商、餘數
*/

#include <stdio.h>

int main(void) {
    int vx, vy;

    puts("請輸入兩個整數：");
    printf("整數vx：");
    scanf("%d", &vx);
    printf("整數vy：");
    scanf("%d", &vy);

    printf("vx + vy = %d\n",  vx + vy);
    printf("vx - vy = %d\n",  vx - vy);
    printf("vx * vy = %d\n",  vx * vy);
    printf("vx / vy = %d\n",  vx / vy);
    printf("vx %% vy = %d\n", vx % vy);

    return (0);
}
