/*
將max定義為函數範本的標頭(C/C++)  "max.h"
*/
#if defined __cplusplus /* C++ */
template <class Type> Type max(Type a, Type b) {
    return (a > b ? a : b);
}
#else /* C */
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif
