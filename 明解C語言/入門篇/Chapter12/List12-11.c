/*
車輛移動與耗用燃料
*/

#include  <math.h>
#include  <stdio.h>

#define sqr(n)    ((n) * (n))

typedef struct {            /*=== 點 ===*/
    int  x;             /* X座標 */
    int  y;             /* Y座標 */
} point;

typedef struct {                /*=== 車輛 ===*/
    double  fuel;           /* 剩餘燃料 */
    point   pt;             /* 目前位置 */
} car;

/*---輸出目前位置和剩餘燃料---*/
void put_info(car c) {
    printf("目前位置：(%d,%d)\n", c.pt.x, c.pt.y);
    printf("剩餘燃料：%.2f升\n",   c.fuel);
}

/*---往X和Y方向只移動(dx, dy)---*/
int move(car* c, int dx, int dy) {
    double  dist = sqrt(sqr(dx) + sqr(dy));     /* 移動距離 */

    if (dist > c->fuel) {
        return (0);    /* 不可移動 */
    }

    c->pt.x += dx;
    c->pt.y += dy;
    c->fuel -= dist;
    return (1);                                 /* 移動成功 */
}

int main(void) {
    car mycar = {90.0, {0.0, 0.0}};

    while (1) {
        int    slct;
        int    dx, dy;                       /* 移動距離 */

        put_info(mycar);
        printf("是否移動【Yes…1／No…0】：");
        scanf("%d", &slct);

        if (slct != 1) {
            break;
        }

        printf("X方向的移動距離：");
        scanf("%d", &dx);
        printf("Y方向的移動距離：");
        scanf("%d", &dy);

        if (!move(&mycar, dx, dy)) {
            puts("\a因燃料不足而不能移動。");
        }
    }

    return (0);
}
