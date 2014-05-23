/*
把標準輸入的輸入內容複製到標準輸出
*/
#include  <stdio.h>

int main(void) {
    int  ch;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    return (0);
}
