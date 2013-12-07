/*******************************
    檔名:ch11_05.c
    功能:移動檔案指標(使用fseek)
 *******************************/

#include <stdlib.h>
#include <stdio.h>

FILE* fp1;

void main(void) {
    char filename1[80];
    char tempstr[32];
    printf("請輸入檔名:");
    scanf("%s", filename1);
    fp1 = fopen(filename1, "r");

    if (fp1 == NULL) {
        printf("檔案發生錯誤\n");
        exit(1);   /* 強迫結束程式 */
    }

    if (fseek(fp1, -17L, SEEK_END) == 0) {
        fscanf(fp1, "%s", tempstr);
        printf("檔尾倒數17個字元處的token是%s\n", tempstr);
    } else {
        printf("fseek產生錯誤\n");
    }

    fclose(fp1);
    /* system("pause"); */
}
