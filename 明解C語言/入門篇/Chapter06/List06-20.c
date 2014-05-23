/*
驗證暗地裡的初始化動作
*/

#include  <stdio.h>

int    fx;                /* 靜態的儲存區間（被0初始化） */

int main(void) {
    static int   sx;      /* 靜態的儲存區間（被0初始化） */
    int          ax;      /* 自動儲存區間（ 被不定數初始化）*/

    printf("ax = %d\n", ax);
    printf("sx = %d\n", sx);
    printf("fx = %d\n", fx);

    return (0);
}
