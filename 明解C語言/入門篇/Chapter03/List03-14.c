/*
  求出兩個整數之差後再輸出（條件運算子）
*/

#include  <stdio.h>

int main(void) {
    int  n1, n2;

    puts("請輸入兩個整數:");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    printf("兩者之差為%d。\n", (n1 > n2) ? n1 - n2 : n2 - n1);


    return (0);
}

