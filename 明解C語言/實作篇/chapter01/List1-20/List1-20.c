/*
    確認未給定初始化子的要素是否以0來做初始化
*/

#include  <stdio.h>

int main(void) {
    int  i;
    int  b[3] = {1};    /*會從前面依序以1,0,0來做初始化*/

    if (b[1] != 0  ||  b[2] != 0) {
        puts("無法正確初始化。");
    } else
        for (i = 0; i < 3; i++) {
            printf("b[%d] = %d\n", i, b[i]);
        }

    system("PAUSE");
    return (0);
}
