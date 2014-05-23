/*
  計算兩個整數之平均數之後再輸出實數
*/

#include <stdio.h>

int main(void) {
    int na, nb;

    puts("請輸入兩個整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    printf("其平均值是%f。\n", (na + nb) / 2.0);

    return (0);
}
