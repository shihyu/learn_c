#include <stdio.h>

int main(int argc, char *argv[])
{
    char *a = 1000;
    int *b = 1000;
    unsigned short *c = 1000;
    float *d = 1000;

    printf("%ld\n",sizeof(unsigned short));

    printf("%ld\n",sizeof(a));
    printf("%ld\n",sizeof(b));
    printf("%ld\n",sizeof(c));
    printf("%ld\n",sizeof(d));

    printf("%d\n",a);
    printf("%d\n",a+1);

    printf("%d\n",b);
    printf("%d\n",b+1);

    printf("%d\n",c);
    printf("%d\n",c+1);

    printf("%d\n",d);
    printf("%d\n",d+1);

    return 0;
}
