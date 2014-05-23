/*
搜尋名字再問候（讀取字串）
*/

#include  <stdio.h>

int main(void) {
    char  name[40];

    printf("您的大名是：");
    scanf("%s", name);

    printf("歡迎您，%s先生 /小姐!!\n", name);

    return (0);
}
