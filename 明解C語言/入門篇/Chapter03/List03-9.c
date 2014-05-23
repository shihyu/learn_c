/*
  判斷整數是正、負數？
*/

#include  <stdio.h>

int main(void) {
    int  no;

    printf("請輸入一個整數：");
    scanf("%d", &no);

    if (no == 0) {
        puts("您輸入的數字是0。");
    } else if (no > 0) {
        puts("您輸入的數字是正數。");
    } else {
        puts("您輸入的數字是負數。");
    }

    return (0);
}

