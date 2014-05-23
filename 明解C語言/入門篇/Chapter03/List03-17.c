/*
  整數除以3的餘數?
*/

#include  <stdio.h>

int main(void) {
    int  num;

    printf("請輸入一個整數：");
    scanf("%d", &num);

    if (num % 3 == 0) {
        puts("此數可以被3除盡。");
    } else if (num % 3 == 1) {
        puts("此數除以3的餘數為1。");
    } else if (num % 3 == 2) {
        puts("此數除以3的餘數為2。");
    }

    return (0);
}

