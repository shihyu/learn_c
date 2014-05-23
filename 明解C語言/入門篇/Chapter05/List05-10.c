/*
  輸入五名學生的成績，再輸出總和與總平均。
*/
#include  <stdio.h>

#define NUMBER  5                   /*人數 */

int main(void) {
    int i;
    int tensu[NUMBER];               /* 學生成績 */
    int sum = 0;                     /* 總和 */

    puts("請輸入成績：");

    for (i = 0; i < NUMBER; i++) {
        printf("%2d號：", i + 1);
        scanf("%d", &tensu[i]);
        sum += tensu[i];
    }

    printf("總和　：%5d\n", sum);
    printf("總平均：%5.1f\n", (double)sum / NUMBER);

    return (0);
}
