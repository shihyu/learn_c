/*
物件的記憶域期間(靜態/自動)與初始化
*/

#include <stdio.h>

int ft = 0; /*靜態記憶域期間*/

void func(void) {
    int at = 0; /*自動記憶域期間*/
    static int st = 0; /*靜態記憶域期間*/

    ft++;
    at++;
    st++;
    printf("ft = %d at = %d st = %d\n", ft, at, st);
}

int main(void) {
    int i;

    for (i = 0; i < 8; i++) {
        func();
    }

    system("PAUSE");
    return (0);
}
