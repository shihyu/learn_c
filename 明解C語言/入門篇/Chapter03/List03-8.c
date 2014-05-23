/*
  整數最末位是否為5?
*/

#include  <stdio.h>

int main(void) {
    int  vx;

    printf("請輸入一個整數：");
    scanf("%d", &vx);

    if (vx % 10 == 5) {
        puts("最末位為5。");
    }

    return (0);
}

