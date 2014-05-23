/*
  顯示兩個整數數值之和
*/

#include <stdio.h>

int main(void) {
    int n1, n2;
    int wa;                   /*和*/

    puts("請輸入兩個整數：");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    wa = n1 + n2;             /*將n1跟n2之和代入wa*/

    printf("上述兩個整數之和是%d。\n", wa); /*顯示數值和*/

    return 0;
}
