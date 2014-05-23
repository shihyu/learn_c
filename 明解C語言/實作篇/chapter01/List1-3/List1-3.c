/*
detab …將水平tab展開的程式"detab.c"
*/
#include <stdio.h>
#include <stdlib.h>
/*---將從src的輸入內容中的tab展開後輸出到dst ---*/
void detab(FILE* src, FILE* dst, int width) {
    int ch;
    int pos = 1;

    while ((ch = fgetc(src)) != EOF) {
        int num;

        switch (ch) {
        case '\t':
            num = width - (pos - 1) % width;

            for (; num > 0; num--) {
                fputc(' ', dst);
                pos++;
            }

            break;

        case '\n':
            fputc(ch, dst);
            pos = 1;
            break;

        default:
            fputc(ch, dst);
            pos++;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    int width = 8; /*預設寬度是8 */
    FILE* fp;

    if (argc < 2) {
        detab(stdin, stdout, width);    /*標準輸入→標準輸出*/
    } else {
        while (--argc > 0) {
            if (**(++argv) == '-') {
                if (*++(*argv) == 't') {
                    width = atoi(++*argv);
                } else {
                    fputs("參數有錯誤。\n", stderr);
                    return (1);
                }
            } else if ((fp = fopen(*argv, "r")) == NULL) {
                fprintf(stderr, "檔案%s無法開啟。\n", *argv);
                return (1);
            } else {
                detab(fp, stdout, width); /* 串流fp→標準輸出*/
                fclose(fp);
            }
        }
    }

    return (0);
}
