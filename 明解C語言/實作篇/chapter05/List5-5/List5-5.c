/*
    複製字串(空敘述的使用例:做為迴圈敘述的主體)
*/

#include  <stdio.h>

/*--- 將字串s複製到d */
char* strcopy(char* d, const char* s) {
    char*  p = d;

    while (*d++ = *s++)
        ;                   /* 空敘述 */

    return (p);
}

int main(void) {
    char  sx[20] = "ABC";
    char  sy[20] = "";

    strcopy(sy, sx);            /* 將字串sx複製到sy */

    printf("字串sx = %s\n", sx);
    printf("字串sy = %s\n", sy);

    system("PAUSE");
    return (0);
}
