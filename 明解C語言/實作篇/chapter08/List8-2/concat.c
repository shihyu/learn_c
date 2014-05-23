/*
    Concat … 檔案複製
*/

#include  <stdio.h>

/*--- 將src的輸入輸出至dst ---*/
void copy(FILE* src, FILE* dst) {
    int  ch;

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
}

int main(int argc, char* argv[]) {
    FILE*  fp;

    if (argc < 2) {
        copy(stdin, stdout);    /* 標準輸入→標準輸出 */
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "檔案%s不能開啟。\n", *argv);
                return (1);
            } else {
                copy(fp, stdout);   /* 串流fp→標準輸出 */
                fclose(fp);
            }
        }
    }

    return (0);
}
