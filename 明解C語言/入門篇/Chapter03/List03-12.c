/*
  求出三個整數中的最大值後再輸出
*/

#include  <stdio.h>

int main(void) {
    int  n1, n2, n3, max;

    puts("請輸入三個整數：");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);
    printf("整數3：");
    scanf("%d", &n3);

    max = n1;

    if (n2 > max) {
        max = n2;
    }

    if (n3 > max) {
        max = n3;
    }

    printf("最大值為%d。\n", max);

    return (0);
}

