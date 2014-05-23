/*
    結構SY的宣告(在成員部分持有SX本身)--"defy.h"
*/

#if !defined(__SY)
#define __SY

#include "defx.h"                 /* 首先引入"def.h" */

typedef struct __sy {
    int  c;
    SX   d;
} SY;

#endif
