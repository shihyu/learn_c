/***************************************
    檔名:ch7_06.c
    功能:函式宣告,定義,呼叫的相對位置
 ***************************************/

#include <stdio.h>
#include <stdlib.h>

void func1(void); /* func1函式宣告 */
void func2(void); /* func2函式宣告 */

void main(void) {
    func1();
    func2();
    /*  system("pause");  */
}

void func1(void) { /* func1函式定義 */
    printf("func1函式正在執行中...\n");
}

void func2(void) { /* func2函式定義 */
    printf("func2函式正在執行中...\n");
}
