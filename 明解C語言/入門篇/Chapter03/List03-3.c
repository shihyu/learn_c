/*
  你所輸入的數字是否能為5整除？
*/

#include  <stdio.h>

int main(void) {
    int  vx;

    printf("請輸入一個整數：");
    scanf("%d", &vx);

    if (vx % 5) {
        puts("您所輸入的數字無法以5除盡。");
    } else {
        puts("您所輸入的數字能以5除盡。");
    }

    return (0);
}

