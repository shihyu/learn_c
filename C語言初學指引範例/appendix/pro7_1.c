/*******************************
    檔名:pro7_1.c
    功能:外在變數宣告(多檔案示範)
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int i;
extern void func1(void);

int main(void) {
    extern int i;     /*  可省略此行 */
    printf("i=%d\n", i);
    func1();
    printf("i=%d\n", i);
    return 0;
    system("pause");/*  system("pause");  */
}
