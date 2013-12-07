/***************************
    檔名:ch7_22.c
    功能:main函式的引數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]) {
    int i;
    printf("本程式共接受到命令列%d個參數\n", argc);

    for (i = 0; i <= argc; i++) {
        printf("argv[%d]字串為%s\n", i, argv[i]);
    }

    /*  system("pause");  */
}
