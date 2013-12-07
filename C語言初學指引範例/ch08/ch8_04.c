/***************************
    檔名:ch8_04.c
    功能:指標變數的加法運算
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;
    short int*  p;
    int*        q;
    float*      r;
    double*     s;
    p = (short int*) &a;
    q = &a;
    r = (float*) &a;
    s = (double*) &a;
    printf("p=%p\n", p);
    printf("q=%p\n", q);
    printf("r=%p\n", r);
    printf("s=%p\n", s);
    printf("=============================\n");
    p = p + 1;
    q = q + 1;
    r = r + 1;
    s = s + 1;
    printf("p=%p\n", p);
    printf("q=%p\n", q);
    printf("r=%p\n", r);
    printf("s=%p\n", s);
    /*  system("pause");  */
    system("pause");
    return 0;
}
