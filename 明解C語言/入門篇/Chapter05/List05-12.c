/*
  輸入五名學生的成績，然後輸出成績達60分以上的學生成績一覽表
*/
#include  <stdio.h>

#define NUMBER 5        /* 人數 */

int main(void) {
    int i;
    int snum = 0;                      /* 及格者人數 */
    int tensu[NUMBER];                 /* NUMBER學生的成績 */
    int succs[NUMBER];                 /* 及格者名單（放入及格者的標註值） */

    puts("請輸入成績：");

    for (i = 0; i < NUMBER; i++) {
        printf("%2d號：", i + 1);
        scanf("%d", &tensu[i]);

        if (tensu[i] >= 60) {
            succs[snum++] = i;    /* 新增到及格者名單 */
        }
    }

    puts("及格者名單一覽表");
    puts("----------------");

    for (i = 0; i < snum; i++) {
        printf("%2d號：(%3d分)\n", succs[i] + 1, tensu[succs[i]]);
    }

    return (0);
}
