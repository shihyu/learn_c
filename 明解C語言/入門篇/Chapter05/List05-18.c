/*
  求出小於1000的質數（第四版）
*/
#include  <stdio.h>

int main(void) {
    int     i, no;
    int     prime[500];                     /* 儲存質數的陣列 */
    int     ptr = 0;                        /* 已知質數的個數 */
    unsigned long  counter = 0;

    prime[ptr++] = 2;                       /* 2是質數 */
    prime[ptr++] = 3;                       /* 3也是質數 */

    for (no = 5 ; no <= 1000; no += 2) {    /* 以奇數為對象 */
        for (i = 1; i < ptr; i++) {         /* 將已知奇數再拿來除 */
            counter++;

            if (no % prime[i] == 0) {       /* 若可以整除就不是質數 */
                break;    /* 至此不要再重複操作 */
            }
        }

        if (ptr == i) {                      /* 最後仍不能整除 */
            prime[ptr++] = no;    /* 增加至陣列中 */
        }
    }

    for (i = 0; i < ptr; i++) {
        printf("%d\n", prime[i]);
    }

    printf("乘除的次數：%lu\n", counter);

    return (0);
}
