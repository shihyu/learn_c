/*------------------------------------------------------------------------*/
/*  逐字元輸入輸出函式庫<實作檔> "getchr.c"      */
/*------------------------------------------------------------------------*/

#include  <stdio.h>
#include  "_getchr.h"
#include  "getchr.h"

char  __buffer[__BUFSIZE];          /* 緩衝區 */
int   __buf_no = 0;             /* 現在的元素個數 */
int   __front_ptr = 0;          /* 前頭元素游標 */
int   __rear_ptr = 0;           /* 末尾元素游標 */

/*--- 取出1字元 ---*/
int getchr(void) {
    if (__buf_no <= 0) {        /* 若緩衝區為空的話 */
        return (getchar());    /* 則從鍵盤讀入並傳回 */
    } else {
        int  temp;
        __buf_no--;
        temp = __buffer[__front_ptr++];

        if (__front_ptr == __BUFSIZE) {
            __front_ptr = 0;
        }

        return (temp);
    }
}
