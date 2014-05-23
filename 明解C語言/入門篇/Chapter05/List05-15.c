/*
  求出小於1000的質數（第一版）
*/
#include  <stdio.h>

int main(void) {
    int   i, no;
    unsigned long  counter = 0;

    for (no = 2; no <= 1000; no++) {
        for (i = 2; i < no; i++) {
            counter++;

            if (no % i == 0) {   /* 能整除就不是質數 */
                break;    /*不要再重複操作 */
            }
        }

        if (no == i) {           /* 到最後仍無法除盡 */
            printf("%d\n", no);
        }
    }

    printf("乘除的次數：%lu\n", counter);

    return (0);
}
