/*
若擁有自動記憶域期間的物件沒有明確指定初始化子的話，裡面會放入不定值，也就是垃圾。
*/
#include <stdio.h>

int main(void) {
    int x; /*會以不定值來做初始化*/

    printf("x = %d\n", x);

    system("PAUSE");
    return (0);
}

