/*
  顯示幾個整數，求其總和以及總平均。（for敘述）
*/
#include  <stdio.h>

int main(void) {
    int i;
    int sum = 0;                       /*總和*/
    int num, tmp;

    printf("有幾個整數：");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("No.%d：", i + 1);
        scanf("%d", &tmp);
        sum += tmp;
    }

    printf("總和：%d\n", sum);
    printf("平均值：%.2f\n", (double)sum / num);

    return (0);
}
