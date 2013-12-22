#include <stdio.h>

int main(int argc, char *argv[])
{
    char a[2][10] = {"Hello", "world"};  // 20 byte
    char (*b)[10] = a; // b 是個指標, 64bit 是8byte
    char *c[2] = {"Hello", "world"}; // 16 byte  
    char d[100] = "egergergergewrgewrgjeiorgjoierjgoiergjoiejgoierjgoijeorgjowjerg"; 

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



    return 0;
}
