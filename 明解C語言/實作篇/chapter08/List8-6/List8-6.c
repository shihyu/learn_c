/*
    將數值以字串方式讀入(改良版)
*/

#include  <ctype.h>
#include  <stdio.h>

/*--- 將字串轉換成int型的值 ---*/
int strtoi(const char* str, int* x) {
    int  sign = 1;              /* 符號 */

    while (isspace(*str)) {     /* 將空白類字元略過 */
        str++;
    }

    switch (*str) {
    case '+' :
        str++;
        break;         /* 正符號 */

    case '-' :
        str++;
        sign = -1;
        break;     /* 負符號 */
    }

    for (*x = 0; *str >= '0'  &&  *str <= '9'; str++) {
        *x = *x * 10 + (*str - '0');
    }

    *x *= sign;

    return (*str ? 0 : 1);
}

int main(void) {
    int   num;
    char  buffer[100];

    while (1) {
        printf("請輸入整數值 : ");
        scanf("%s", buffer);

        if (!strtoi(buffer, &num)) {
            puts("\a無法轉換成整數值。");
        } else {
            if (num == 9999) {
                break;
            }

            printf("您輸入的值為%d。\n", num);
        }
    }

    system("PAUSE");
    return (0);
}
