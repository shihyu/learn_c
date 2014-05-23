/*
  陣列各元素分別依序為1、2、3、4、5並輸出結果
*/
#include  <stdio.h>

int main(void) {
    int  vc[5];                   /* 元素個數為5的陣列 */

    vc[0] = 1;
    vc[1] = 2;
    vc[2] = 3;
    vc[3] = 4;
    vc[4] = 5;

    printf("vc[0] = %d\n", vc[0]);
    printf("vc[1] = %d\n", vc[1]);
    printf("vc[2] = %d\n", vc[2]);
    printf("vc[3] = %d\n", vc[3]);
    printf("vc[4] = %d\n", vc[4]);

    return (0);
}
