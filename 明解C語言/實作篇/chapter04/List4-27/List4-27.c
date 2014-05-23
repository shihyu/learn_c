/*
    動態產生字串的陣列
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main(void) {
    int   i;
    char*  p[4];

    for (i = 0; i < 4; i++) {
        char  temp[128];

        printf("請輸入字串 : ");
        scanf("%s", temp);

        p[i] = malloc(strlen(temp) + 1);    /* 動態產生字串領域 */

        if (p[i]) {
            strcpy(p[i], temp);
        }
    }

    for (i = 0; i < 4; i++) {
        printf("p[%d] = %s\n", i, p[i]);
    }

    for (i = 0; i < 4; i++) {
        free(p[i]);    /* 釋放儲存空間 */
    }

    system("PAUSE");
    return (0);
}
