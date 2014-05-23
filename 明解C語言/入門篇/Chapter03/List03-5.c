/*
  輸入之整數是否非零？
*/

#include  <stdio.h>

int main(void) {
    int  num;

    printf("請輸入一個整數：");
    scanf("%d", &num);

    if (num) {
        puts("您所輸入的數字非0。");
    } else {
        puts("您所輸入的數字是0。");
    }

    return (0);
}
