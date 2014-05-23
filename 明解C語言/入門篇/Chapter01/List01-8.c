/*
在兩個變數的地方代入整數後顯示
*/

#include <stdio.h>

int main(void) {
    int vx, vy;               /*vx和vy是int型變數之值*/

    vx = 57;                  /*在vx代入57*/
    vy = vx + 10;             /*在vy代入vx+10*/

    printf("vx 之值為%d。\n", vx);    /*顯示vx之值*/
    printf("vy 之值為%d。\n", vy);    /*顯示vy之值*/

    return (0);
}
