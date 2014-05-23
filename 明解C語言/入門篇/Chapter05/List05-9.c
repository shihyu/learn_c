/*
  輸入五名學生的成績，再輸出總和與總平均。
*/
#include  <stdio.h>

int main(void) {
    int i;
    int tensu[5];                     /*五個學生的成績*/
    int sum = 0;                      /*總分數*/

    puts("請輸入分數：");

    for (i = 0; i < 5; i++) {
        printf("%2d號：", i + 1);
        scanf("%d", &tensu[i]);
        sum += tensu[i];
    }

    printf("總和　：%5d\n", sum);
    printf("總平均：%5.1f\n", (double)sum / 5);

    return (0);
}
