/*
    逐字元輸入輸出函式庫(第3版)--"getchr.c"
*/

#include  <stdio.h>

#define BUFSIZE     256         /* 緩衝區的大小 */

char  buffer[BUFSIZE];              /* 緩衝區 */
int   buf_no = 0;                   /* 現在的元素個數 */
int   front_ptr = 0;                /* 前頭元素游標 */
int   rear_ptr = 0;                 /* 末尾元素游標 */

/*--- 取出一字元 ---*/
int getchr(void) {
    if (buf_no <= 0) {              /* 若緩衝區為空的話 */
        return (getchar());    /* 從鍵盤讀入一字並傳回 */
    } else {
        int  temp;

        buf_no--;
        temp = buffer[front_ptr++];

        if (front_ptr == BUFSIZE) {
            front_ptr = 0;
        }

        return (temp);
    }
}
