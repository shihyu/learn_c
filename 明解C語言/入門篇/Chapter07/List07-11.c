/*
求兩點間距離
*/

#include  <math.h>
#include  <stdio.h>

/*---求點(x1, y1)和點(x2, y2)的距離---*/
double dist(double x1, double y1, double x2, double y2) {
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int main(void) {
    double  x1, y1;     /* 點1 */
    double  x2, y2;     /* 點2 */

    printf("<點1> X座標：");
    scanf("%lf", &x1);
    printf("      Y座標：");
    scanf("%lf", &y1);
    printf("<點2> X座標：");
    scanf("%lf", &x2);
    printf("      Y座標：");
    scanf("%lf", &y2);

    printf("兩點間的距離為%f。\n", dist(x1, y1, x2, y2));

    return (0);
}
