/*
使用自身的不定值來做初始化
*/

#include <stdio.h>

int x = 1;

int main(void) {
    int x = x; /*用自己的值來做初始化*/

    printf("x = %d\n", x);

    system("PAUSE");
    return (0);
}
