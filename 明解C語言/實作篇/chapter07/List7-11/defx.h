/*
    結構SX的宣告(在成員部分有著指向結構SY的指標)--"defx.h"
*/

typedef struct {
    int  a;
    SY*   b;        /* 指向結構SY的指標 */
} SX;
