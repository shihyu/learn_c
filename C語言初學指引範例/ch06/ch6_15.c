/*******************************************
    檔名:ch6_15.c
    功能:strcmp()與strncmp()練習-比較字串
 *******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char s1[] = "output";
    char s2[] = "outside";
    char s3[] = "output";
    char s4[] = "outlook";
    printf("%s與%s\t的比較結果==>%d\n", s1, s1, strcmp(s1, s1));
    printf("%s與%s\t的比較結果==>%d\n", s1, s2, strcmp(s1, s2));
    printf("%s與%s\t的比較結果==>%d\n", s1, s3, strcmp(s1, s3));
    printf("%s與%s\t的比較結果==>%d\n", s1, s4, strcmp(s1, s4));
    printf("%s與%s\t的前3個字元比較結果==>%d\n", s1, s2, strncmp(s1, s2, 3));
    /*  system("pause");  */
}
