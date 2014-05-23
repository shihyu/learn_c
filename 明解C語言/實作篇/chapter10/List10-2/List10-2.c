/*
    理解函式呼叫與堆疊的程式範例
*/

#include  <stdio.h>

void fa(void) {
    puts("□□□函式fa開始");
    puts("□□□函式fa結束");
}

void fb(void) {
    puts("□□□函式fb開始");
    puts("□□□函式fb結束");
}

void fc(void) {
    puts("□□函式fc開始");

    fa();                               /* 呼叫函式fa */

    fb();                               /* 呼叫函式fb */

    puts("□□函式fc結束");
}

int main(void) {
    puts("□main函式開始");

    fc();                               /* 呼叫函式fc */

    puts("□main函式結束");

    return (0);
}
