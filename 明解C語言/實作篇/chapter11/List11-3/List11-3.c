/*
    逐字元輸入輸出函式庫(第2版)
*/

#include  <stdio.h>

#define BUFSIZE     256         /*緩衝區大小 */

static char   buffer[BUFSIZE];          /* 緩衝區 */
static int    buf_no = 0;               /* 現在的元素個數 */
static int    front_ptr = 0;            /* 前頭元素游標 */
static int    rear_ptr = 0;             /* 末尾元素游標 */

int getchr(void) {
    if (buf_no <= 0) {
        return (getchar());
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

int ungetchr(int ch) {
    if (buf_no >= BUFSIZE) {
        return (EOF);
    } else {
        buf_no++;
        buffer[rear_ptr++] = ch;

        if (rear_ptr == BUFSIZE) {
            rear_ptr = 0;
        }

        return (ch);
    }
}
