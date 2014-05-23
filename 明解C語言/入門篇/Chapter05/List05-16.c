/*
  求1000以下的質數（第二版）
*/
#include  <stdio.h>

int main(void) {
    int    i, no;
    unsigned long  counter = 0;

    no = 2;
    printf("%d\n", no++);                   /* 2是偶數中唯一的質數 */

    for (; no <= 1000; no += 2) {            /* 以奇數為對象 */
        for (i = 2; i < no; i++) {
            counter++;

            if (no % i == 0) {              /* 可以被整除所以不數質數*/
                break;    /* 不要重複操作 */
            }
        }

        if (no == i) {                      /* 到最後不能被整除 */
            printf("%d\n", no);
        }
    }

    printf("乘除的次數：%lu\n", counter);

    return (0);
}
