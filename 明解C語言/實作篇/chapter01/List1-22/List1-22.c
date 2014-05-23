/*
    確認typedef名稱的陣列初始化
*/

#include  <stdio.h>

int main(void) {
    int  i;
    typedef int  Int5ary[5];    /*元素型為int型且元素數為5的陣列型*/
    Int5ary  x = {1, 2, 3};

    for (i = 0; i < 5; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    system("PAUSE");
    return (0);
}
