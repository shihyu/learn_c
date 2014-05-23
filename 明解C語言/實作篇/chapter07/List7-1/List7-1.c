/*
    結構物件的初始化(初始化子不足的元素將以0來初始化
*/

#include  <stdio.h>

int main(void) {
    struct {
        int     x;
        double  y;
    } s = {1};                      /* x將以1來初始化，y將以0來初始化 */

    printf("s.x = %d\n", s.x);      /* 顯示物件s成員x的值 */
    printf("s.y = %f\n", s.y);      /* 顯示物件s成員y的值 */

    system("PAUSE");
    return (0);
}
