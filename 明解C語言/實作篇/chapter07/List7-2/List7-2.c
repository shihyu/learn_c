/*
    使用巨集來對結構給定名稱(<1>錯誤版)
*/

#define complex  struct { double re, im; }

int main(void) {
    complex  a, b;
    complex  x, y;

    a = b;      /* 正確 */
    x = b;      /* 不正確 */

    return (0);
}
