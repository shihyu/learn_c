/*
  輸入之整數是奇數或偶數？
*/

#include  <stdio.h>

int main(void) {
    int  no;

    printf("請輸入一個整數：");
    scanf("%d", &no);

    if (no % 2) {
        puts("您所輸入的數字是奇數。");
    } else {
        puts("您所輸入的數字是偶數。");
    }

    return (0);
}

