/*
求兩點間的距離
*/

#include  <math.h>
#include  <stdio.h>

#define sqr(n)    ((n) * (n))     /*求平方值*/

typedef struct {                  /*=== 點 ===*/
    int  x;                   /* X座標 */
    int  y;                   /* Y座標 */
} point;

/*---傳回點pa和點pb之間的距離---*/
double distanceof(point pa, point pb) {
    return (sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y)));
}

int main(void) {
    point   p1, p2;

    printf("點1的X座標：");
    scanf("%d", &p1.x);
    printf("     Y座標：");
    scanf("%d", &p1.y);
    printf("點2的X座標：");
    scanf("%d", &p2.x);
    printf("     Y座標：");
    scanf("%d", &p2.y);

    printf("兩點間的距離為%.2f。\n", distanceof(p1, p2));

    return (0);
}
