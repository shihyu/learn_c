/*
  將陣列各元素依序以1、2、3、4、5初始化後再輸出結果
*/
#include  <stdio.h>

int main(void) {
    int  i;
    int  vc[5] = {1, 2, 3, 4, 5};             /* 初始化 */

    for (i = 0; i < 5; i++) {
        printf("vc[%d] = %d\n", i, vc[i]);
    }

    return (0);
}

