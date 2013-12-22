#include <stdio.h>

int main(int argc, char *argv[])
{
    char a[2][10] = {"Hello", "world"};  // 20 byte
    char (*b)[10] = a; // b 是個指標, 64bit 是8byte
    char *c[2] = {"Hello", "world"}; // 16 byte  
    char d[100] = "egergergergewrgewrgjeiorgjoierjgoiergjoiejgoierjgoijeorgjowjerg"; 
    int e[2][2][2] = {{{10,20},{30,40}},
                      {{50,60},{70,80}}};

    printf("%ld\n",sizeof(a));
    printf("%ld\n",sizeof(b));
    printf("%ld\n",sizeof(c));
    printf("%ld\n\n",sizeof(d));

    printf("a[0]=%s\n", a[0]);
    printf("a[1]=%s\n", a[1]);
    printf("*a=%s\n", *(a));
    printf("*(a+1)=%s\n\n", *(a+1));

    printf("b[0]=%s\n", b[0]);
    printf("b[1]=%s\n", b[1]);
    printf("*b=%s\n", *(b));
    printf("*(b+1)=%s\n\n", *(b+1));

    printf("*c=%s\n", *(c));
    printf("*(c+1)=%s\n", *(c+1));
    printf("c[0]=%s\n", c[0]);
    printf("c[1]=%s\n\n", c[1]);

    c[0] = d;

    printf("%s\n\n",c[0]);

    printf("e[0][0][0]=%d\n",e[0][0][0]);
    printf("*(*(*(e+0)+0)+0)=%d\n",*(*(*(e+0)+0)+0));
    printf("e[0][0][0]=%d\n",e[1][1][1]);
    printf("*(*(*(e+1)+1)+1)=%d\n\n",*(*(*(e+1)+1)+1));

    // address
    printf("a    address=%p\n",a);
    printf("a[0] address=%p\n",a[0]);
    printf("b    address=%p\n",b);
    printf("b    address=%p\n",a[1]);
    printf("b    address=%p\n",*(b+1));

    return 0;
}
