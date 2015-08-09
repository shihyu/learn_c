/*
自動儲存區間與靜態儲存區間
*/

#include  <stdio.h>

int    fx = 0;                          /* 靜態儲存區間+檔案有效範圍 */

void func(void) {
    static int       sx = 0;           /* 靜態儲存區間+資料段有效範圍 */
    int              ax = 0;           /* 自動儲存區間+資料段有效範圍 */


    printf("%3d%3d%3d\n", ax++, sx++, fx++);
}

int main(void) {
    int    i;

    puts(" ax sx fx");
    puts("----------");

    for (i = 0; i < 10; i++) {
        func();
    }

    puts("----------");

    return (0);
}
