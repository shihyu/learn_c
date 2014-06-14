#include <stdio.h>

// void test(int e)  //  call by value
void test(int e, int *p)  // call by address
{
    int a = 100;
    int b = 200;
    int c = 300;
    int d = 400;

    // printf("test fuc %d\n",a);
    // printf("test fuc %p\n",&a);
    // printf("test fuc %d\n",b);
    // printf("test fuc %p\n",&b);
    // printf("test fuc %d\n",c);
    // printf("test fuc %p\n",&c);
    // printf("test fuc %d\n",d);
    // printf("test fuc %p\n",&d);

    printf("test fuc %d\n",e);
    printf("test fuc %p\n",&e);

    printf("test fuc %p\n",p);
    printf("test fuc %d\n",*p);
    *p = 34534;
}

int main(int argc, char *argv[])
{
    int a = 100;
    int b = 200;
    int c = 300;
    int d = 400;
    int e = 500;

    // printf("main fun %d\n",a);
    // printf("main fun %p\n",&a);
    // printf("main fun %d\n",b);
    // printf("main fun %p\n",&b);
    // printf("main fun %d\n",c);
    // printf("main fun %p\n",&c);
    // printf("main fun %d\n",d);
    // printf("main fun %p\n",&d);
    printf("main fun %d\n",e);
    printf("main fun %p\n",&e);
    printf("\n\n");
    test(e, &e);
    printf("main fun %d\n",e);



    return 0;
}
