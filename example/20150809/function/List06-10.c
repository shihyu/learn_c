/*
求出最高分
*/

#include  <stdio.h>

#define  NUMBER 5

int tensu[NUMBER];

int top(void);             /* 【函數原型宣告】 */

int main(void) {
    extern int  tensu[];
    int  i;

    printf("請輸入%d名學生的成績。\n", NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("%d：", i + 1);
        scanf("%d", &tensu[i]);
    }

    printf("最高分=%d\n", top());

    return (0);
}

/*--- 傳回陣列tensu的最大值【函數定義】---*/
int top(void) {
    extern int  tensu[];
    int  i;
    int  max = tensu[0];

    for (i = 1; i < NUMBER; i++)
        if (tensu[i] > max) {
            max = tensu[i];
        }

    return (max);
}
