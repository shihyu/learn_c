/*
  從0開始計數到某正整數之值
*/
#include  <stdio.h>

int main(void) {
    int i, no;

    printf("請輸入一個正整數：");
    scanf("%d", &no);

    i = 0;

    while (i <= no) {
        printf("%d ", i++);    /*輸出顯示i值後再遞增 */
    }

    putchar('\n');

    return (0);
}

