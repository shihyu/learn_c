/*
   計算兩個整數的平均值之後再輸出成實數（cast）
*/

#include  <stdio.h>

int main(void) {
    int  na, nb;

    puts("請輸入兩個整數:");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    printf("其平均值是%f。\n", (double)(na + nb) / 2);    /* cast */

    return (0);
}

