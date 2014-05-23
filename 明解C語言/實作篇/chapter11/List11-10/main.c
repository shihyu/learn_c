/*------------------------------------------------------------------------*/
/*  逐字元輸入輸出函式庫的使用例                      "main.c"          */
/*------------------------------------------------------------------------*/

#include  <ctype.h>
#include  <stdio.h>
#include  "getchr.h"

/*----- 讀入整數(數字排列)，並顯示加倍後的值 -----*/
int getnum(void) {
    int  c = 0;
    int  x = 0;
    int  ch;

    while ((ch = getchr()) != EOF  &&  isdigit(ch)) {
        x = x * 10 + ch - '0';
        c++;
    }

    if (ch != EOF) {
        ungetchr(ch);
    }

    if (c) {
        printf("%d\n", x * 2);
    }

    return (ch);
}

/*----- 讀入字元並直接顯示 -----*/
int getnnum(void) {
    int  ch;

    while ((ch = getchr()) != EOF  &&  !isdigit(ch)) {
        putchar(ch);
    }

    if (ch != EOF) {
        ungetchr(ch);
    }

    putchar('\n');

    return (ch);
}

int main(void) {
    while (getnum() != EOF)
        if (getnnum() == EOF) {
            break;
        }

    return (0);
}
