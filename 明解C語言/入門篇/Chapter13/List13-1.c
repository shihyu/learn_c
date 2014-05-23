/*
   開啟檔案與關閉檔案
*/
#include  <stdio.h>

int main(void) {
    FILE*  fp;

    fp = fopen("abc", "r") ;                       /* 開啟檔案 */

    if (fp == NULL) {
        printf("\a無法開啟檔案。 \n");
    } else {
        /* 從檔案寫入資料 */
        fclose(fp) ;                             /* 關閉檔案 */
    }

    return (0) ;
}
