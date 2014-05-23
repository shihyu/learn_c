/*
  求出兩個整數中何者為大、何者為小後再輸出
*/

#include  <stdio.h>

int main(void) {
    int  n1, n2, max, min;

    puts("請輸入兩個整數:");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    if (n1 > n2)  {
        max = n1;
        min = n2;
    } else {
        max = n2;
        min = n1;
    }

    printf("兩者中較大值為%d。\n", max);
    printf("兩者中較小值為%d。\n", min);

    return (0);
}

