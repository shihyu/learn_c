#include <stdio.h>

void swap(int *a, int *b)
{
    printf("swap[+] a=%d, b=%d\n",*a,*b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("swap[-] a=%d, b=%d\n",*a,*b);
}

int main(int argc, char *argv[])
{

    int a, b;

    a = 50;
    b = 100;
    printf("a=%d, b=%d\n",a,b);
    swap(&a,&b);
    printf("a=%d, b=%d\n",a,b);

    return 0;
}
