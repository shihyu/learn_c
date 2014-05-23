/*
  整數除以3的餘數（switch敘述）
*/

#include  <stdio.h>

int main(void) {
    int  num;

    printf("請輸入一個整數：");
    scanf("%d", &num);

    switch (num % 3) {
    case 0 :
        puts("此數可以被3除盡。");
        break;

    case 1 :
        puts("此數除以3的餘數為1。");
        break;

    case 2 :
        puts("此數除以3的餘數為2。");
        break;
    }

    return (0);
}

