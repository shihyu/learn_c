/*
  陣列各元素分別依序指定為1、2、3、4、5並輸出結果（for敘述）
*/
#include  <stdio.h>

int main(void) {
    int  i;
    int  vc[5];     /* 元素個數為5的陣列 */

    for (i = 0; i < 5; i++) {
        vc[i] = i + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("vc[%d] = %d\n", i, vc[i]);
    }

    return (0);
}

