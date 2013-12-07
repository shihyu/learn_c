/*******************************
    檔名:ch6_16.c
    功能:strtok()練習-取出token
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char string1[] = "Word:Excel:PowerPointer:Access;C;Java;ASP:PHP";
    char delim1[] = ":,;";
    char* Token;                    /* 指標字串,請見指標章節說明  */
    printf("原始字串為%s\n", string1);
    printf("開始切割..........\n");
    printf("Tokens(句元)如下:\n");
    Token = strtok(string1, delim1); /* 將第一個句元存入Token */

    while (Token != NULL) {         /* 使用迴圈取出剩餘句元 */
        printf("%s\n", Token);
        Token = strtok(NULL, delim1);
    }

    /*  system("pause");  */
}
