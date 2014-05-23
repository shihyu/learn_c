/*
複製字串
*/

#include  <stdio.h>

/*---將字串s複製到d---*/
char* str_copy(char* d, const char* s) {
    char*  t = d;

    while (*d++ = *s++)
        ;

    return (t);
}

int main(void) {
    char  s1[128] = "ABCD";
    char  s2[128] = "EFGH";

    printf("請輸入字串s1：");
    scanf("%s", s1);

    str_copy(s2, s1);

    puts("s1已複製到s2。");
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    return (0);
}
