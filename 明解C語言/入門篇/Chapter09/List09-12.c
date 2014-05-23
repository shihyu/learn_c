/*
輸出字串陣列
*/

#include  <stdio.h>

/*---輸出字串陣列（逐一輸出字元）---*/
void put_strary2(const char st[][6], int n) {
    int     i;

    for (i = 0; i < n; i++) {
        int  j = 0;
        printf("st[%d]=\"", i);

        while (st[i][j]) {
            putchar(st[i][j++]);
        }

        puts("\"");
    }
}

int main(void) {
    char  cs[][6] = {"Turbo", "NA", "DOHC"};

    put_strary2(cs, 3);

    return (0);
}
