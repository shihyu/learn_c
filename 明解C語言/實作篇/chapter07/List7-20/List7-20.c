/*
    共同空間
*/

#include  <stdio.h>

int main(void) {
    union uxy {
        int     x;
        double  y;
    } s;

    s.x = 1;
    printf("s.x = %d\n", s.x);
    printf("s.y = %f\n", s.y);

    system("PAUSE");
    return (0);
}

