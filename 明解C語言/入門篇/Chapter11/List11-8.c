/*
複製字串（這是個錯誤的範例）

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
    char  str[128] = "ABCD";
    char*  ptr     = "EFGH";

    printf("請輸入字串str：");
    scanf("%s", str);

    str_copy(ptr, str);

    puts("str已複製到ptr。");
    printf("str = %s\n", str);
    printf("ptr = %s\n", ptr);

    return (0);
}
