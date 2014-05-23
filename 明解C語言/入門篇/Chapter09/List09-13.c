/*
將字串內的英文字母改成大寫／小寫
*/

#include  <ctype.h>
#include  <stdio.h>

/*---把字串內的英文字母改成大寫---*/
void str_toupper(char str[]) {
    unsigned  i = 0;

    while (str[i]) {
        str[i] = toupper(str[i]);
        i++;
    }
}

/*---把字串內的英文字母改成小寫---*/
void str_tolower(char str[]) {
    unsigned i = 0;

    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main(void) {
    char  str[100];

    printf("請輸入一個字串：");
    scanf("%s", str);

    str_toupper(str);
    printf("大寫：%s\n", str);

    str_tolower(str);
    printf("小寫：%s\n", str);

    return (0);
}
