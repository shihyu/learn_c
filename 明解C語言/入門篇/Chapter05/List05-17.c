/*
  求出小於1000的質數（第三版）
*/
#include  <stdio.h>

int main(void) {
    int    i, no;
    unsigned long  counter = 0;

    no = 2;
    printf("%d\n", no++);                 /* 2是偶數唯一的質數 */

    for (; no <= 1000; no += 2) {          /* 只有奇數才列入範圍*/
        for (i = 3; i < no; i += 2) {     /* 只有奇數才拿來除 */
            counter++;

            if (no % i == 0) {            /* 如果可以整除就不是質數 */
                break;    /* 不要重複操作 */
            }
        }

        if (no == i) {                    /* 到最後不能整除 */
            printf("%d\n", no);
        }
    }

    printf("乘除的次數：%lu\n", counter);

    return (0);
}
