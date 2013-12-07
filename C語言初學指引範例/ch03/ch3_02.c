/***************************
    檔名:ch3_02.c
    功能:算數運算子
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x, y;
    x = 20;
    y = 7;
    printf("當x=%d", x);
    printf(",y=%d時\n", y);
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y); /* y不可為0 */
    printf("x %% y = %d\n", x % y); /* y不可為0 */
    system("pause");
}
