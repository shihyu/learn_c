/*
    整數與浮點數
*/

#include  <stdio.h>

int main(void) {
    int     nx;             /* 整數 */
    double  dx;             /* 浮點數 */

    nx = 9.99;
    dx = 9.99;

    printf("int   型態變數nx之值：%d\n", nx);      /*    9      */
    printf("              nx/2  ：%d\n", nx / 2);  /*    9 / 2  */

    printf("double型態變數dx之值：%f\n", dx);      /* 9.99      */
    printf("              dx/2.0：%f\n", dx / 2.0); /* 9.99 /2.0 */

    return (0);
}

