/*
  輸入五名學生的成績，再輸出總和與總平均。
*/
#include  <stdio.h>

int main(void) {
    int  uchida;                          /* 甲生的成績 */
    int  satoh;                           /* 乙生的成績 */
    int  sanaka;                          /* 丙生的成績 */
    int  hiraki;                          /* 丁生的成績 */
    int  masaki;                          /* 戊生的成績 */
    int  sum = 0;                         /* 總和 */

    puts("請輸入分數。");
    printf("1號：");
    scanf("%d", &uchida);
    printf("2號：");
    scanf("%d", &satoh);
    printf("3號：");
    scanf("%d", &sanaka);
    printf("4號：");
    scanf("%d", &hiraki);
    printf("5號：");
    scanf("%d", &masaki);

    sum += uchida;
    sum += satoh;
    sum += sanaka;
    sum += hiraki;
    sum += masaki;

    printf("總和  ：%5d\n", sum);
    printf("總平均：%5.1f\n", (double)sum / 5);

    return (0);
}
