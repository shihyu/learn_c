/*
    dmp¡KÀÉ®×ªº±Æ¥X
*/

#include  <ctype.h>
#include  <stdio.h>

/*--- ±N¦ê¬ysrcªº¤º®e±Æ¥X¨ìdstƒv ---*/
void dump(FILE* src, FILE* dst) {
    int            n;
    unsigned long  count = 0;
    unsigned char  buf[16];

    while ((n = fread(buf, 1, 16, src)) > 0) {
        int  i;

        fprintf(dst, "%08lX ", count);                      /* ¦ì§} */

        for (i = 0; i < n; i++) {                           /* 16¶i¦ì¼Æ */
            fprintf(dst, "%02X ", (unsigned)buf[i]);
        }

        if (n < 16)
            for (i = n; i < 16; i++) {
                fputs("   ", dst);
            }

        for (i = 0; i < n; i++) {                           /* ¦r¤¸ */
            fputc(isprint(buf[i]) ? buf[i] : '.', dst);
        }

        fputc('\n', dst);

        count += 16;
    }

    fputc('\n', dst);
}

int main(int argc, char* argv[]) {
    FILE*  fp;

    if (argc < 2) {
        fputs("½Ð«ü©wÀÉ®×¡C\n", stderr);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "rb")) == NULL) {
                fprintf(stderr, "ÀÉ®×%sµLªk¶}±Ò¡C\n", *argv);
                return (1);
            } else {
                dump(fp, stdout);    /* ¦ê¬yfp¡÷¼Ð·Ç¿é¥X */
                fclose(fp);
            }
        }
    }

    return (0);
}
