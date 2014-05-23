/*
    動態產生讀入字串的複製品
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main(void) {
    char  st[128];
    char*  pt;

    printf("請輸入字串st : ");
    scanf("%s", st);

    pt = malloc(strlen(st) * 2);    /* 動態產生稍長的字串 */

    if (pt) {
        strcpy(pt, st);     /* 複製至產生後的領域 */
        printf("st = %s\n", st);
        printf("pt = %s\n", pt);
        /* 將pt重複使用，代入別的字串 */
        free(pt);           /* 釋放儲存空間 */
    }

    system("PAUSE");
    return (0);
}
