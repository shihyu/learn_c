/*************************************
    檔名:ch11_02.c
    功能:複製檔案(使用fgetc與fputc)
 *************************************/

#include <stdlib.h>
#include <stdio.h>

FILE* fp1, *fp2;

void main(void) {
    char filename1[80], filename2[80];
    char c;
    printf("請輸入來源檔名:");
    scanf("%s", filename1);
    printf("請輸入目的檔名:");
    scanf("%s", filename2);
    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "w");

    if ((fp1 == NULL) || (fp2 == NULL)) {
        printf("檔案發生錯誤\n");
        exit(1);   /* 強迫結束程式 */
    }

    printf("讀取並寫入中......\n");

    while ((c = fgetc(fp1)) != EOF) { /*  使用迴圈讀取來源檔內容  */
        printf("%c", c);
        fputc(c, fp2); /*  使用迴圈寫入目的檔內容  */
    }

    printf("\n讀取並寫入完畢......\n");
    fclose(fp1);
    fclose(fp2);
    /* system("pause"); */
}
