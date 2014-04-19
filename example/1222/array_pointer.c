#include <stdio.h>

int main(int argc, char *argv[]) {
    char a[2][10] = {"Hello", "world"};  // 20 byte
    char(*b)[10] = a;  // b 是個指標, 64bit 是8byte
    char *c[2] = {"Hello", "world"}; // 16 byte
    char d[100] = "egergergergewrgewrgjeiorgjoierjgoiergjoiejgoierjgoijeorgjowjerg";
    <<< <<< < HEAD
    char *e = "c";
    char *f = "hello";
    char g[100000] = "abcdefghij";
    int i;
    == == == =
    int e[2][2][2] = {{{10, 20}, {30, 40}},
        {{50, 60}, {70, 80}}
    };
    >>> >>> > aa6c888a7fcba8083d712f1c92b5620060ee5537
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));
    printf("%ld\n\n", sizeof(d));
    printf("a[0]=%s\n", a[0]);
    printf("a[1]=%s\n", a[1]);
    printf("*a=%s\n", *(a));
    printf("*(a+1)=%s\n\n", *(a + 1));
    printf("b[0]=%s\n", b[0]);
    printf("b[1]=%s\n", b[1]);
    printf("*b=%s\n", *(b));
    printf("*(b+1)=%s\n\n", *(b + 1));
    printf("*c=%s\n", *(c));
    printf("*(c+1)=%s\n", *(c + 1));
    printf("c[0]=%s\n", c[0]);
    printf("c[1]=%s\n\n", c[1]);
    c[0] = d;
    printf("%s\n\n", c[0]);
    <<< <<< < HEAD
    printf("%c\n", *(e + 0)); // 相當於 *e
    printf("%c\n", *(e + 1));
    printf("%s\n", f);
    printf("%c\n", *f);
    printf("%c\n", *(f + 4));
    c[0] = e; // 相當於 *c = e , *(c+0) = e
    c[1] = f; //  相當於 *(c+1) = f
    printf("%s\n", c[0]);
    printf("%s\n", c[1]);
    printf("%c\n", *(g + 8));
    printf("%c\n", *(g + 9));

    for (i = 0; i < 100000; ++i) {
        printf("%p, i=%d\n", g + i, i);
        g[i] = 'y';
    }

    printf("%ld\n", sizeof(g));
    == == == =
        printf("e[0][0][0]=%d\n", e[0][0][0]);
    printf("*(*(*(e+0)+0)+0)=%d\n", *(*(*(e + 0) + 0) + 0));
    printf("e[0][0][0]=%d\n", e[1][1][1]);
    printf("*(*(*(e+1)+1)+1)=%d\n\n", *(*(*(e + 1) + 1) + 1));
    >>> >>> > aa6c888a7fcba8083d712f1c92b5620060ee5537
    // address
    printf("a    address=%p\n", a);
    printf("a[0] address=%p\n", a[0]);
    printf("b    address=%p\n", b);
    printf("b    address=%p\n", a[1]);
    printf("b    address=%p\n", *(b + 1));
    return 0;
}
