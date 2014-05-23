/*
    逐字元輸入輸出函式庫(第3版)--"ungetchr.c"
*/

#include  <stdio.h>

#define BUFSIZE     256     /* 緩衝區大小 */

extern char  buffer[BUFSIZE];       /* 緩衝區 */
extern int   buf_no;                /* 現在的元素個數 */
extern int   front_ptr;             /* 前頭元素游標 */
extern int   rear_ptr;              /* 末尾元素游標 */

/*--- 推回一字元 ---*/
int ungetchr(int ch) {
    if (buf_no >= BUFSIZE) {    /* 若緩衝區已滿 */
        return (EOF);    /* 則無法再推回 */
    } else {
        buf_no++;
        buffer[rear_ptr++] = ch;

        if (rear_ptr == BUFSIZE) {
            rear_ptr = 0;
        }

        return (ch);
    }
}
