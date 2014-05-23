/*
    確認使用typedef名時，不完全的初始化
*/

#include  <stdio.h>

int main(void) {
    int   i;
    typedef int IntAry[];             /*元素型為int的陣列型*/
    IntAry  a = {1, 2, 3};            /*元素數為3 */
    IntAry  b = {1, 2, 3, 4, 5};      /*元素數為5 */

    for (i = 0; i < 3; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    for (i = 0; i < 5; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    system("PAUSE");
    return (0);
}
