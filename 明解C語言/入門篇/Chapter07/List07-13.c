/*
求出陣列的元素個數
*/

#include  <stdio.h>

int main(void) {
    int     vi[10];
    double  vd[25];

    printf("陣列vi的元素個數 = %u\n", sizeof(vi) / sizeof(vi[0]));
    printf("陣列vd的元素個數 = %u\n", sizeof(vd) / sizeof(vd[0]));

    return (0);
}
