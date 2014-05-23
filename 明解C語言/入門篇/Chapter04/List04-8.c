/*
  將某整數倒數計數到0（第二版）
*/

#include  <stdio.h>

int main(void) {
    int no;

    printf("請輸入一個正整數：");
    scanf("%d", &no);

    while (no >= 0) {
        printf("%d ", no--);    /* 輸入no之值後再遞減 */
    }

    putchar('\n');

    return (0);
}
