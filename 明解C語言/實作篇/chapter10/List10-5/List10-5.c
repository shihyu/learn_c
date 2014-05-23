/*
    將堆疊破壞的程式
*/

#include  <stdio.h>

/*--- 將堆疊破壞的函式 ---*/
void func(void) {
    int   i;
    char  x[4];

    puts("函式func執行中。");

    for (i = -2; i < 6; i++) {
        x[i] = 0;
    }
}

int main(void) {
    puts("呼叫函式func。");
    func();
    puts("函式func結束。");

    return (0);
}
