/*
  求出小於1000的質數（第五版）
*/
#include  <stdio.h>

int main(void) {
    int    i, no;
    int    prime[500];               /* 儲存質數的陣列 */
    int    ptr = 0;                  /* 已知的質數個數 */
    unsigned long  counter = 0;
    prime[ptr++] = 2;                /* 2是質數 */
    prime[ptr++] = 3;                /* 3也是質數 */

    for (no = 5; no <= 1000; no += 2) {
        int   flag = 0;

        for (i = 1; counter++, prime[i] * prime[i] <= no; i++) {
            counter++;

            if (no % prime[i] == 0) {    /* 可以整除就不是質數 */
                flag = 1;
                break;                   /* 不須複操作 */
            }
        }

        if (!flag) {                           /* 到最後仍不能整除 */
            prime[ptr++] = no;    /* 增加至陣列中 */
        }
    }

    for (i = 0; i < ptr; i++) {
        printf("%d\n", prime[i]);
    }

    printf("乘除次數：%lu\n", counter);

    return (0);
}
