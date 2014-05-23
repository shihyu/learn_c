/*
計算從標準輸入的輸入過程中已出現過的數字字元
*/

#include  <stdio.h>

int main(void) {
    int  i, ch;
    int  cnt[10] = {0};     /* 所有的元素以0進行初始化 */

    while (1) {         /* 無窮迴圈 */
        ch = getchar();

        if (ch == EOF) {
            break;
        }

        switch (ch) {
        case '0' :
            cnt[0]++;
            break;

        case '1' :
            cnt[1]++;
            break;

        case '2' :
            cnt[2]++;
            break;

        case '3' :
            cnt[3]++;
            break;

        case '4' :
            cnt[4]++;
            break;

        case '5' :
            cnt[5]++;
            break;

        case '6' :
            cnt[6]++;
            break;

        case '7' :
            cnt[7]++;
            break;

        case '8' :
            cnt[8]++;
            break;

        case '9' :
            cnt[9]++;
            break;
        }
    }

    puts("數字字元的出現次數");

    for (i = 0; i < 10; i++) {
        printf("'%d':%d\n", i, cnt[i]);
    }

    return (0);
}
