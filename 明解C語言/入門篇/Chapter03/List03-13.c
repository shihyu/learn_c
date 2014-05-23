/*
  求出兩個整數中較大者之值後再輸出（條件運算子）
*/

#include  <stdio.h>

int main(void) {
    int  n1, n2, max;

    puts("請輸入兩個整數:");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    max = (n1 > n2) ? n1 : n2;        /* 將較大者之值代入max */

    printf("兩者中較大者之值為%d。\n", max);

    return (0);
}

