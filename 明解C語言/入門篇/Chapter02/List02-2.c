/*
  輸出某個整數數值的最末位數字
*/

#include <stdio.h>

int main(void) {
    int no;

    printf("請輸入整數：");
    scanf("%d", &no);
    printf("最末位數字是%d。\n", no % 10);

    return (0);
}
