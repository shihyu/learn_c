/***********************************
    檔名:ch9_10.c
    功能:外在變數宣告(單一檔案示範)
 ***********************************/

#include <stdio.h>
#include <stdlib.h>

int i;

void func1(void) {
    extern int i;      /* 可省略此行 */
    i++;
}

void main(void) {
    extern int i;     /* 可省略此行 */
    printf("i=%d\n", i);
    func1();
    printf("i=%d\n", i);
    /*  system("pause");  */
}
