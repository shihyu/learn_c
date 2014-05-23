/*
    顯示檔案的內容
*/
#include <stdio.h>

int  main(void) {
    int    ch ;
    FILE*  fp ;
    char  fname[64] ;    /* 檔案名稱 */

    printf(" 檔案名稱：") ;
    scanf("%s" , fname) ;

    if ((fp = fopen(fname, "r")) == NULL) {            /* 開啟 */
        printf("\a 無法開啟檔案。 \n") ;
    } else {
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch) ;
        }

        fclose(fp) ;
    }                                                  /* 關閉 */

    return (0) ;
}
