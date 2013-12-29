#include <stdio.h>

int main(int argc, char *argv[])
{
    char a[2][10] = {"Hello", "world"};  // 20 byte
    char (*b)[10] = a; // b 是個指標, 64bit 是8byte
    char *c[2] = {"Hello", "world"}; // 16 byte  
    char d[100] = "egergergergewrgewrgjeiorgjoierjgoiergjoiejgoierjgoijeorgjowjerg"; 
    char *e = "c";
    char *f = "hello";
    char g[100000] = "abcdefghij";
    int i;

    printf("%ld\n",sizeof(a));
    printf("%ld\n",sizeof(b));
    printf("%ld\n",sizeof(c));
    printf("%ld\n",sizeof(d));

    printf("a=%s\n", a[0]);
    printf("a=%s\n", a[1]);
    printf("a=%s\n", *a);
    printf("a=%s\n", *(a+1));

    printf("b=%s\n", b[0]);
    printf("b=%s\n", b[1]);
    printf("b=%s\n", *(b));
    printf("b=%s\n", *(b+1));

    printf("c=%s\n", *(c));
    printf("c=%s\n", *(c+1));
    printf("c=%s\n", c[0]);
    printf("c=%s\n", c[1]);

    c[0] = d;

    printf("%s\n",c[0]);

    printf("%c\n",*(e+0));  // 相當於 *e
    printf("%c\n",*(e+1));
    printf("%s\n",f);
    printf("%c\n",*f);
    printf("%c\n",*(f+4));

    c[0] = e; // 相當於 *c = e , *(c+0) = e
    c[1] = f; //  相當於 *(c+1) = f
    printf("%s\n", c[0]);
    printf("%s\n", c[1]);

    printf("%c\n",*(g+8));
    printf("%c\n",*(g+9));


    for (i = 0; i < 100000; ++i) {
        printf("%p, i=%d\n",g +i, i);
        g[i] = 'y';
    }
    
    printf("%ld\n",sizeof(g));


    return 0;
}
