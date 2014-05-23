/*
  連續輸出相當於某正整數之值個數的＊記號
*/
#include  <stdio.h>

int main(void) {
    int no;

    printf("請輸入一個正整數：");
    scanf("%d", &no);

    while (no-- > 0) {
        putchar('*');
    }

    putchar('\n');

    return (0);
}

