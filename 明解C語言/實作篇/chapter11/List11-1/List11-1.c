/*
    逐字元輸入輸出函式庫
*/

#include  <stdio.h>

#define BUFSIZE     256         /* 緩衝區的大小 */

char  buffer[BUFSIZE];              /* 緩衝區 */
int   buf_no = 0;                   /* 現在的元素個數 */
int   front_ptr = 0;                /* 前頭元素游標 */
int   rear_ptr = 0;                 /* 末尾元素游標 */

/*--- 取出一字 ---*/
int getchr(void) {
    if (buf_no <= 0) {              /* 若緩衝區為空的話 */
        return (getchar());    /* 則從鍵盤讀入並傳回 */
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

/*--- 推回一字 ---*/
int ungetchr(int ch) {
    if (buf_no >= BUFSIZE) {        /* 若緩衝區為滿的話 */
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
