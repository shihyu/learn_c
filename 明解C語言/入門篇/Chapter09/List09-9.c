/*
一個字、一個字輸出字串
*/

#include  <stdio.h>

/*---輸出字串（不換行）---*/
void put_string(const char str[]) {
    unsigned  i = 0;

    while (str[i]) {
        putchar(str[i++]);
    }
}

int main(void) {
    char  str[100];

    printf("請輸入一個字串:");
    scanf("%s", str);

    put_string(str);
    putchar('\n');

    return (0);
}
