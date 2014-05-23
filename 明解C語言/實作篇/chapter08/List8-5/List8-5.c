/*
    將數值讀文字串(atoi函式版)
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int   num;
    char  buffer[100];

    while (1) {
        printf("請輸入整數值 : ");

        if (scanf("%s", buffer) == EOF) {
            break;
        }

        if ((num = atoi(buffer)) == 9999) {
            break;
        }

        printf("您輸入的值為%d。\n", num);
    }

    system("PAUSE");
    return (0);
}
