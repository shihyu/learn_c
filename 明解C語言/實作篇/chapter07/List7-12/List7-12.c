/*
    結構SX以及SY的宣告
*/

typedef struct __sy  SY;    /* 先把SY宣告起來 */

typedef struct {
    int  a;
    SY*   b;                /* 由於已經知道SY存在，所以放心下去宣告 */
} SX;

typedef struct __sy {
    int  c;
    SX   d;                 /* 由於已經知道SX的內容，所以放心下去宣告 */
} SY;
