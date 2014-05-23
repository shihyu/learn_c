/*
計算字串內的數字字元
*/

#include  <stdio.h>

/*---字串str內的數字字元被存入陣列cnt---*/
void str_dcount(const char str[], int cnt[]) {
    unsigned  i = 0;

    while (str[i]) {
        if (str[i] >= '0'  &&  str[i] <= '9') {
            cnt[str[i] - '0']++;
        }

        i++;
    }
}

int main(void) {
    int   i;
    int   dcnt[10] = {0};
    char  str[100];

    printf("請輸入一個字串：");
    scanf("%s", str);

    str_dcount(str, dcnt);

    puts("數字字元所出現的次數");

    for (i = 0; i < 10; i++) {
        printf("'%d':%d\n", i, dcnt[i]);
    }

    return (0);
}
