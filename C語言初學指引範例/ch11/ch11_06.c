/*********************************
    檔名:ch11_06.c
    功能:複製檔案(可複製二進位檔)
 *********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE* fp1, *fp2;

void main(int argc, char* argv[]) {
    char src_filename[128];  /*  來源檔案  */
    char dest_filename[128]; /*  目的檔案  */
    int ch;

    if (argc <= 2) { /*  提示使用者輸入來源檔名與目的檔名  */
        printf("請輸入來源檔名與目的檔名\n");
        exit(0);
    } else {
        strcpy(src_filename, argv[1]);
        strcpy(dest_filename, argv[2]);
    }

    if ((fp1 = fopen(src_filename, "rb")) == NULL) {
        printf("開啟來源檔%s錯誤\n", src_filename);
        exit(0);
    }

    if ((fp2 = fopen(dest_filename, "wb")) == NULL) {
        printf("無法建立目的檔%s\n", dest_filename);
        exit(0);
    }

    while ((ch = fgetc(fp1)) != EOF) { /*  當讀到EOF時,表示檔案結束  */
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    /* system("pause"); */
}
