/*
  將某整數倒數計數到0
*/

#include  <stdio.h>

int main(void) {
    int no;

    printf("請輸入一個整數：");
    scanf("%d", &no);

    while (no >= 0)  {
        printf("%d ", no);
        no--;               /* no之值遞減 */
    }

    putchar('\n');          /* 換行 */

    return (0);
}
