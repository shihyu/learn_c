/*
    動態產生字串的複製品
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main(void) {
    char  st[128];
    char*  pt;

    printf("請輸入字串st : ");
    scanf("%s", st);

    pt = malloc(strlen(st) + 1);      /* 動態產生出字串領域 */

    if (pt) {
        strcpy(pt, st);               /* 複製到產生後的領域 */
        printf("st = %s\n", st);
        printf("pt = %s\n", pt);
        free(pt);                     /* 釋放儲存空間 */
    }

    system("PAUSE");
    return (0);
}
