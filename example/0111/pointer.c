#include <stdio.h>

int main(int argc, char *argv[])
{
    char *a = (char*)1000;
    int *b = (int*)1000;
    unsigned short *c = (unsigned short*)1000;
    float *d = (float*)1000;

    printf("%ld\n",sizeof(unsigned short));

    printf("%ld\n",sizeof(a));
    printf("%ld\n",sizeof(b));
    printf("%ld\n",sizeof(c));
    printf("%ld\n",sizeof(d));

    printf("%ld\n",(unsigned long)a);
    printf("%ld\n",(unsigned long)(a+1));

    printf("%ld\n",(unsigned long)b);
    printf("%ld\n",(unsigned long)(b+1));

    printf("%ld\n",(unsigned long)c);
    printf("%ld\n",(unsigned long)(c+1));

    printf("%ld\n",(unsigned long)d);
    printf("%ld\n",(unsigned long)(d+1));
    return 0;
}
