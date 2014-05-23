/*
    複製檔案
*/
#include  <stdio.h>

int  main(void) {
    int    ch;
    FILE*  sfp, *dfp;
    char   sname[64], dname[64];     /* 檔案名稱 */

    printf("要進行複製的檔案名稱：");
    scanf("%s" , sname);
    printf("貼上複製字串的檔案名稱：") ;
    scanf("%s" , dname);

    if ((sfp = fopen(sname, "r")) == NULL) {       /*開啟要進行複製的檔案*/
        printf("\a無法開啟要進行複製的檔案。\n") ;
    } else {
        if ((dfp = fopen(dname , "w")) == NULL) {     /*開啟要貼上字串的檔案*/
            printf("\a 無法開啟要貼上複製字串的檔案。\n") ;
        } else {
            while ((ch = fgetc(sfp)) != EOF) {
                fputc(ch , dfp) ;
            }

            fclose(dfp) ;                       /*關閉要貼上字串的檔案*/
        }

        fclose(sfp) ;                           /*關閉要進行複製的檔案*/
    }

    return (0) ;
}
