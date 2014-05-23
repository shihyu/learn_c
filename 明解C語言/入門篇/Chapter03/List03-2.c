/*
  輸入之整數是奇數？
*/

#include  <stdio.h>

int main(void) {
    int  no;

    printf("請輸入一個整數：");
    scanf("%d", &no);

    if (no % 2) {
        puts("您所輸入的數字是奇數。");
    }

    return (0);
}

