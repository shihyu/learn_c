/*
顯示所讀取整數數值的10倍
*/

#include <stdio.h>

int main(void) {
    int no;

    printf("請輸入整數：");
    scanf("%d", &no);

    printf("該整數的10倍是%d。\n", 10 * no);

    return (0);
}
