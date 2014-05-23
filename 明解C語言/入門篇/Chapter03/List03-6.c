/*
  輸入之整數是否相等？
*/

#include  <stdio.h>

int main(void) {
    int  x1, x2;

    puts("請輸入兩個整數：");
    printf("整數1：");
    scanf("%d", &x1);
    printf("整數2：");
    scanf("%d", &x2);

    if (x1 == x2) {
        puts("兩者的數值相等。");
    } else {
        puts("兩者的數值不相等。");
    }

    return (0);
}

