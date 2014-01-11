#include <stdio.h>


void test(int* a);
// void test(int a[]);

int main(int argc, char* argv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("main a[0]=%d\n", a[0]);
    printf("main a[9]=%d\n", a[9]);
    printf("%ld\n", sizeof(a));
    test(a);
    printf("%ld\n", sizeof(a));
    printf("main a[0]=%d\n", a[0]);
    printf("main a[9]=%d\n", a[9]);
    return 0;
}

void test(int* a)
//void test(int a[])
{
    int* b;
    int c;
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));
    printf("%ld\n", sizeof(a));
    printf("test a[0]=%d\n", a[0]);
    printf("test a[9]=%d\n", a[9]);
    a[0] = 1000;
    a[9] = 2000;
    printf("test a[0]=%d\n", a[0]);
    printf("test a[9]=%d\n", a[9]);
}
