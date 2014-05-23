/*------------------------------------------------------------------------*/
/*  逐字元輸入輸出函式庫<內部標頭>  "_getchr.h"*/
/*------------------------------------------------------------------------*/

#if !defined(__GETCHR_)
#define __GETCHR_

#define __BUFSIZE   256

extern char  __buffer[__BUFSIZE];   /* 緩衝區 */
extern int   __buf_no;          /* 現在的元素數 */
extern int   __front_ptr;           /* 前頭元素游標 */
extern int   __rear_ptr;            /* 末尾元素游標 */

#endif
