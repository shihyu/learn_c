/*
  顯示兩個整數數之和
*/

#include <stdio.h>

int main(void) {
    int n1, n2;

    puts("請輸入兩個整數：");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    printf("上述兩整數之和是%d。\n", n1 + n2);     /* 顯示數值和 */

    return (0);
}
