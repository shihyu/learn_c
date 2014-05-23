/*
  求出兩個整數中較大者之值後再輸出
*/

#include  <stdio.h>

int main(void) {
    int  n1, n2, max;

    puts("請輸入兩個整數:");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    if (n1 > n2) {
        max = n1;
    } else {
        max = n2;
    }

    printf("兩者中較大者之值為%d。\n", max);

    return (0);
}

