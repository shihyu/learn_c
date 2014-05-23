/*
    使用巨集來對結構給定名稱(<2>)
*/

struct __comp  {
    double re, im;
};

#define complex     struct __comp

int main(void) {
    complex  a, b;
    complex  x, y;

    a = b;          /* 正確 */
    x = b;          /* 正確 */

    system("PAUSE");
    return (0);
}
