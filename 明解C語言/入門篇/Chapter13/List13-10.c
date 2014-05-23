/*
    以字串與編碼顯示檔案的內容
*/
#include  <ctype.h>
#include  <stdio.h>

int main(void) {
    int            n ;
    unsigned long   count = 0 ;
    unsigned char   buf [ 16 ] ;
    FILE*  fp ;
    char   fname[ 64 ];     /* 檔案名稱 */

    printf(" 檔案名稱：") ;
    scanf("%s" , fname) ;

    if ((fp = fopen(fname, "rb")) == NULL) {                     /* 開啟 */
        printf("\a 無法開啟檔案。\n") ;
    } else {
        while ((n = fread(buf , 1, 16, fp)) > 0) {
            int  i ;

            printf("%081x " , count) ;                          /* 位址 */

            for (i = 0 ; i < 16 ; i ++) {                          /* 十六進位 */
                printf("%02x " , (unsigned) buf [ i ]) ;
            }

            if (n < 16)
                for (i = n ; i < 16 ; i ++) {
                    printf("   ") ;
                }

            for (i = 0 ; i < n ; i ++) {                           /* 字串 */
                putchar(isprint(buf[ i ]) ? buf[ i ] : '.') ;
            }

            putchar('\n') ;

            count += 16 ;
        }

        fclose(fp) ;                                           /* 關閉 */
    }

    return (0) ;
}
