/*
    透過指標來間接地變更物件的值
*/

#include  <stdio.h>

int main(void) {
    int  x = 5;                     /*x家有5人*/
    int  y = 3;                     /*y家有3人*/
    int*  ptr;

    ptr = &x;                       /*ptr指著x*/
    printf("x    = %d\n", x);
    printf("y    = %d\n", y);
    printf("ptr  = %p\n", ptr);     /*ptr所指的位址*/
    printf("*ptr = %d\n\n", *ptr);  /*ptr所指的變數的值*/

    ptr = &y;                                          /*ptr指著y*/
    *ptr = 4;                                          /*透過ptr來變更y家的人數*/
    printf("x    = %d\n", x);
    printf("y    = %d\n", y);
    printf("ptr  = %p\n", ptr);                        /*ptr所指的位址*/
    printf("*ptr = %d\n", *ptr);                       /* ptr所指的變數的值*/

    system("PAUSE");
    return (0);
}
