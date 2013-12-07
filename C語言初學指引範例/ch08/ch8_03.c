/***************************
    檔名:ch8_03.c
    功能:指標變數的指定運算
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a = 100;
    int* p, *q;
    printf("============宣告變數時=============\n");
    printf("&a=%p\t a=%d\n", &a, a);
    printf("&p=%p\n", &p);
    printf("&q=%p\n", &q);
    p = &a;
    printf("============設定p=&a後=============\n");
    printf("p=%p\t *p=%d\n", p, *p);
    q = p;
    printf("============設定q=p後=============\n");
    printf("q=%p\t *q=%d\n", q, *q);
    *q = 50;
    printf("===========設定*q=50後============\n");
    printf("p=%p\t *p=%d\n", p, *p);
    printf("q=%p\t *q=%d\n", q, *q);
    printf("a=%d\n", a);
    /*  system("pause");  */
    system("pause");
    return 0;
}
