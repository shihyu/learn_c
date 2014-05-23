/*
變數的有效範圍與初始化
*/
#include <stdio.h>

int z = 1;

int main(void) {
    int x = z;
    int z = 0;
    int y = z;

    system("PAUSE");
    return (0);
}
