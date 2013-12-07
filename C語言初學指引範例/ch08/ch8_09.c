/********************************
    檔名:ch8_09.c
    功能:普通字元陣列與字元字串
 ********************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char s1[] = {'W', 'e', 'l', 'c', 'o', 'm', 'e'};
    char s2[] = "Welcome";
    printf("s1字元陣列佔用記憶體%d bytes\n", sizeof(s1));
    printf("s2字元字串佔用記憶體%d bytes\n", sizeof(s2));
    /*  system("pause");  */
}
