/*
    使用巨集來對結構給定名稱(<3>錯誤版)
*/

struct __comp  {
    double re, im;
};

#define complex     struct __comp
#define compptr     struct __comp *

int main(void) {
    complex  a, b;
    compptr  pa, pb;

    pa = &a;            /* 正確 */
    pb = &b;            /* 不正確 */

    return (0);
}
