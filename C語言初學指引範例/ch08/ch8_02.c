/*******************************************
    檔名:ch8_02.c
    功能:指標變數的內容以及指標變數的大小
 *******************************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int a = 100;
    double b = 5.5;
    int* ptr1 = &a;             /* 相當於  int *ptr1; 及  ptr1=&a;  */
    double* ptr2 = &b;          /* 相當於  double *ptr2; 及  ptr2=&b;  */
    printf("a=%d\n", a);
    printf("b=%e\n", b);
    printf("&a=%p\n", &a);
    printf("&b=%p\n", &b);
    printf("*ptr1=%d\n", *ptr1);
    printf("*ptr2=%e\n", *ptr2);
    printf("ptr1=%p\n", ptr1);
    printf("ptr2=%p\n", ptr2);
    printf("&ptr1=%p\n", &ptr1);
    printf("&ptr2=%p\n", &ptr2);
    printf("&*ptr1=%p\n", &*ptr1);     /*   &*ptr1相當於&a相當於ptr1  */
    printf("&*ptr2=%p\n", &*ptr2);     /*   &*ptr2相當於&b相當於ptr2  */
    printf("===============================\n");
    printf("變數a佔用%d個位元組\n", sizeof(a));
    printf("變數b佔用%d個位元組\n", sizeof(b));
    printf("===============================\n");
    printf("變數ptr1佔用%d個位元組\n", sizeof(ptr1));
    printf("變數ptr2佔用%d個位元組\n", sizeof(ptr2));
    /*  system("pause");  */
}
