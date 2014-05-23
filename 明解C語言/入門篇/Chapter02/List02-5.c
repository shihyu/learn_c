/*
  計算兩個整數的平均值之後再輸出
*/

#include <stdio.h>

int main(void) {
    int na, nb;

    puts("請輸入整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    printf("其平均值是%d。\n", (na + nb) / 2);

    return (0);
}
