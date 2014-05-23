/*
  共同空間的初始化
*/

#include  <stdio.h>

int main(void) {
    union uxy {
        int     x;
        double  y;
    } s = {5}, t = s;

    printf("s.x = %d\n", s.x);
    printf("s.y = %f\n", s.y);
    printf("t.x = %d\n", t.x);
    printf("t.y = %f\n", t.y);

    system("PAUSE");
    return (0);
}

