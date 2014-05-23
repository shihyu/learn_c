/*
  輸入五名學生的成績，再求出最高分和最低分。
*/

#include  <stdio.h>
#define NUMBER  5       /* 人數 */

int main(void) {
    int i;
    int tensu[NUMBER];                /* 學生成績 */
    int max, min;                     /* 最高分、最低分 */

    puts("請輸入成績：");

    for (i = 0; i < NUMBER; i++) {
        printf("%2d號：", i + 1);
        scanf("%d", &tensu[i]);
    }

    min = max = tensu[0];

    for (i = 1; i < NUMBER; i++) {
        if (tensu[i] > max) {
            max = tensu[i];
        }

        if (tensu[i] < min) {
            min = tensu[i];
        }
    }

    printf("最高分：%d\n", max);
    printf("最低分：%d\n", min);

    return (0);
}
