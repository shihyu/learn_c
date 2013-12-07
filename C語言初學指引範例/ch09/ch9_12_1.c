/************************************
    檔名:ch9_12_1.c
    功能:靜態外在變數宣告(多檔案示範)
 ************************************/

#include <stdio.h>
#include <stdlib.h>

int i = 10;
static int j = 10;

extern void func1(void);

int main(void) {
    extern int i;     /*  可省略此行  */
    extern int j;     /*  可省略此行  */
    func1();
    printf("ch9_12_2.c檔的i=%d\n", i);
    printf("ch9_12_2.c檔的j=%d\n", j);
    return 0;
    /*  system("pause");  */
}
