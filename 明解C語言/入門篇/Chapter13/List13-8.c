/*
    先將圓周率的值寫入文字檔，再讀取該檔案
*/
#include  <stdio.h>

int main(void) {
    FILE*   fp ;
    double  pi = 3.14159265358979323846 ;

    /* 寫入 */
    if ((fp = fopen("pi.txt", "w")) == NULL) {    /* 開啟 */
        printf("\a 無法開啟檔案。\n") ;
    } else {
        fprintf(fp, "%f", pi) ;                   /* 寫入pi */
        fclose(fp) ;                              /* 關閉 */
    }

    /* 讀取 */
    if ((fp = fopen("pi.txt" , "r")) == NULL) {     /* 開啟 */
        printf("\a 無法開啟檔案。\n") ;
    } else {
        fscanf(fp, "%1f", &pi) ;                    /* 從pi讀取 */
        printf("圓周率是%23.21f。\n", pi) ;
        fclose(fp);                                 /* 關閉 */
    }

    return (0) ;
}
