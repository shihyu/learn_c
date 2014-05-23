/*------------------------------------------------------------------------*/
/*  逐字元輸入輸出函式庫<實作檔>               "ungetchr.c"      */
/*------------------------------------------------------------------------*/

#include  <stdio.h>
#include  "_getchr.h"
#include  "getchr.h"

/*--- 推回1字元 ---*/
int ungetchr(int ch) {
    if (__buf_no >= __BUFSIZE) {    /* 若緩衝區為滿的話 */
        return (EOF);    /* 則無法再推回 */
    } else {
        __buf_no++;
        __buffer[__rear_ptr++] = ch;

        if (__rear_ptr == __BUFSIZE) {
            __rear_ptr = 0;
        }

        return (ch);
    }
}
