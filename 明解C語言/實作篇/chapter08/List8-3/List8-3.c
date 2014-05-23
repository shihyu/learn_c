/*
    使用函式將單字讀入的解法
*/

#include  <stdio.h>

struct rec {
    char  a[9];     /* 下單日 */
    char  b[7];     /* 商品種類 */
    char  c[9];     /* 交貨日 */
    char  d[10];    /* 金額 */
    char  e[8];     /* 單價 */
};

/*-----------------------------------------------------------------------
    將單字讀分(假設單字是以縮排/換行字元區隔，並忽略空白文字)
-----------------------------------------------------------------------*/
int fgetword(char* str, FILE* fp) {
    int  ch;

    while ((ch = fgetc(fp)) != EOF  &&  ch != '\t'  &&  ch != '\n') {
        if (ch != ' ') {
            *str++ = ch;
        }
    }

    *str = '\0';
    return (ch);
}

/*-----------------------------------------------------------------------
    讀入一件資料
-----------------------------------------------------------------------*/
int getrec(struct rec* dat, FILE* fp) {
    if (fgetword(dat->a, fp) == EOF) {
        return (EOF);    /* 下單日 */
    }

    if (fgetword(dat->b, fp) == EOF) {
        return (EOF);    /* 商品種類 */
    }

    if (fgetword(dat->c, fp) == EOF) {
        return (EOF);    /* 交貨日 */
    }

    if (fgetword(dat->d, fp) == EOF) {
        return (EOF);    /* 金額 */
    }

    if (fgetword(dat->e, fp) == EOF) {
        return (EOF);    /* 單價 */
    }

    return (0);
}

int main(void) {
    FILE*  fp;
    struct rec  dat;

    fp = fopen("data2.txt", "r");       /* 不完全的資料 */

    while (getrec(&dat, fp) == 0) {
        printf("%s\t%s\t%s\t%s\t%s\n",
               dat.a, dat.b, dat.c, dat.d, dat.e);
    }

    fclose(fp);

    system("PAUSE");
    return (0);
}
