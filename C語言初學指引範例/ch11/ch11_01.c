/*******************************
    檔名:ch11_01.c
    功能:開檔與關檔
 *******************************/

#include <stdlib.h>
#include <stdio.h>

FILE* fp1;

void main(void) {
    char filename[80];
    printf("請輸入檔名(可含路徑):");
    scanf("%s", filename);
    fp1 = fopen(filename, "r");

    if (fp1 != NULL) {
        printf("檔案%s開啟中...\n", filename);
    } else {
        printf("檔案%s開啟失敗\n", filename);
        exit(1); /* 強迫結束程式 */
    }

    fclose(fp1);
    printf("檔案%S關閉\n", filename);
    /* system("pause"); */
}
