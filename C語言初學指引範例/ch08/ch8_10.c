/***************************
    檔名:ch8_10.c
    功能:指標字串
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char* s3 = "Welcome";
    int i;

    for (i = 0; i < 8; i++)
        if (s3[i] != '\0') {
            printf("s3[%d]=%c\n", i, s3[i]);
        } else {
            printf("s3[%d]='\\0'\n", i);
        }

    /*  system("pause");  */
}
