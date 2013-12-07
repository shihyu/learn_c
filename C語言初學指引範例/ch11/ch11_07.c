/*******************************
    檔名:ch11_07.c
    功能:讀寫二進位檔
 *******************************/

#include <stdlib.h>
#include <stdio.h>

FILE* fp;

void main(int argc, char* argv[]) {
    char output[] = "This is a binary file!";
    char input[100] = {0};
    int num;

    /************寫入二進位檔 ****************/
    if ((fp = fopen("data3", "wb")) == NULL) {
        printf("檔案錯誤\n");
        exit(0);
    }

    num = fwrite(output, sizeof(char), sizeof(output), fp);
    printf("二進位檔寫入完成\n");
    fclose(fp);

    /************讀取二進位檔 ****************/

    if ((fp = fopen("data3", "rb")) == NULL) {
        printf("檔案錯誤\n");
        exit(0);
    }

    num = fread(input, sizeof(char), 23, fp);
    printf("二進位檔讀取完成\n");
    printf("二進位檔內容如下\n");
    printf("%s\n", input);
    fclose(fp);
    /* system("pause"); */
}
