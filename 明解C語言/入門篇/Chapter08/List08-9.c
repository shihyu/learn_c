/*
計算從標準輸入的輸入過程中已出現過的數字字元（第二版）
*/

#include  <stdio.h>

int main(void) {
    int  i, ch;
    int  cnt[10] = {0};     /* 所有的元素以0進行初始化 */

    while (1) {             /* 無限迴圈 */
        ch = getchar();

        if (ch == EOF) {
            break;
        }

        if (ch >= '0'  &&  ch <= '9') {
            cnt[ch - '0']++;
        }
    }

    puts("數字字元的出現次數");

    for (i = 0; i < 10; i++) {
        printf("'%d':%d\n", i, cnt[i]);
    }

    return (0);
}
