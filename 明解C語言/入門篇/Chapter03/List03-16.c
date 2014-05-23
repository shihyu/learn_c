/*
  輸入月份的季節
*/

#include  <stdio.h>

int main(void) {
    int  month;

    printf("請輸入月份：");
    scanf("%d", &month);

    if (month >= 3 && month <= 5) {
        puts("這個月份是春天。");
    } else if (month >= 6 && month <= 8) {
        puts("這個月份是夏天。");
    } else if (month >= 9 && month <= 11) {
        puts("這個月份是秋天。");
    } else if (month == 1  ||  month == 2  ||  month == 12) {
        puts("這個月份是冬天。");
    } else {
        puts("您輸入的月份不存在！\a");
    }

    return (0);
}

