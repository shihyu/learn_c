/*
    先將圓周率的值寫入二進位檔，再讀取該檔案。
*/

#include  <stdio.h>

int main(void) {
    FILE*    fp;
    double  pi = 3.14159265358979323846;

    /* 寫入 */
    if ((fp = fopen("PI.bin", "wb")) == NULL) {        /* 開啟 */
        printf("\a 無法開啟檔案。\n") ;
    } else {
        fwrite(&pi, sizeof(double) , 1, fp) ;            /* 將資料寫入pi */
        fclose(fp) ;
    }                                                   /* 關閉 */

    /* 讀取 */
    if ((fp = fopen("PI.bin", "rb")) == NULL) {       /* 開啟 */
        printf("\a 無法開啟檔案。\n") ;
    } else {
        fread(&pi, sizeof(double) , 1, fp) ;            /* 從pi讀取資料 */
        printf("圓周率是%23.21f。\n", pi);
        fclose(fp) ;                                    /* 關閉 */
    }

    return (0) ;
}
