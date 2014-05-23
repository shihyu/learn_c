/*
    結構SX的宣告(在成員的部分持有指向結構SY的指標)--"defx.h"
*/

#if !defined(__SX)
#define __SX

typedef struct __sy  SY;          /* 純粹宣告，定義在"defy.h"中 */

typedef struct {
    int  a;
    SY*   b;
} SX;

#endif
