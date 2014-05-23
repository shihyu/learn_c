/*
  輸入幾個整數，求其總和以及總平均。
*/

#include  <stdio.h>

int main(void) {
    int i = 0;
    int sum = 0;            /* 總和 */
    int num, tmp;

    printf("有幾個整數：");
    scanf("%d", &num);

    while (i < num) {
        printf("No.%d：", ++i);
        scanf("%d", &tmp);
        sum += tmp;
    }

    printf("總和：%d\n", sum);
    printf("總平均：%.2f\n", (double)sum / num);

    return (0);
}
