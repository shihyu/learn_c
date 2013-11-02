#include <stdio.h>

int main(int argc, char *argv[])
{
    long long l = 0xAAAABBBBFFFF1234;
    int i = 0xFAFABBAA;
    short int s = 0xFFF1;
    char  c = 0x1F;

    printf("%ld\n",sizeof(l));
    printf("%ld\n",sizeof(i));
    printf("%ld\n",sizeof(s));
    printf("%ld\n",sizeof(c));

    printf("%llX\n",l);
    printf("%X\n",i);
    printf("%hX\n",s);
    printf("%hhX\n",c);

    return 0;
}

