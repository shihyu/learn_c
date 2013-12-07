/************************************
    檔名:ch9_12_2.c
    功能:靜態外在變數宣告(多檔案示範)
 ************************************/

#include <stdio.h>
#include <stdlib.h>

extern int i;
int j; /* extern int j; */

void func1(void) {
    j = 100;
    printf("ch9_12_2.c檔的i=%d\n", i);
    printf("ch9_12_2.c檔的j=%d\n", j);
}
