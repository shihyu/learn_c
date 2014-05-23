/*
#使用#if來做程式註解
*/
#include <stdio.h>
#define DEBUG 0
int main(void) {
    int a = 5;
    int x = 1;
#if DEBUG == 1
    a = x; /* 代入a的值 */
#endif
    printf("a的值為%d。\n", a);
    return (0);
}
