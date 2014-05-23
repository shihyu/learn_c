/*
    使用typedef宣告對結構給定名稱(1)
*/

typedef struct {
    double re, im;
} complex;

int main(void) {
    complex  a, b;
    complex  x, y;
    complex*  pa, *pb;

    a = b;          /* 正確 */
    x = b;          /* 正確 */
    pa = &a;        /* 正確 */
    pb = &b;        /* 正確 */

    system("PAUSE");
    return (0);
}
