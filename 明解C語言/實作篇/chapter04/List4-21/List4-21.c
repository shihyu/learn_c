/*
    將單字從程式讀入的程式(改良版)
*/

#include  <ctype.h>
#include  <stdio.h>

#define Q_NO    3               /* 問題的個數 */

FILE*  fp;

/*--- 初始處理 ---*/
int initialize(void) {
    fp = fopen("DATA", "r");
    return ((fp == NULL) ? 0 : 1);
}

/*--- 結束處理 ---*/
void ending(void) {
    fclose(fp);
}

/*--- 主函式 ---*/
int main(void) {
    if (initialize()) {
        int   q, ch;
        char  qus[20];          /* 問題用字串 */
        char  ans[20];          /* 解答用字串 */

        for (q = 0; q < Q_NO; q++) {
            int  i;

            ch = fgetc(fp);

            if (ch == EOF) {
                goto ending;
            }

            for (i = 0; !(isspace(ch)); i++) {
                qus[i] = ch;
                ch = fgetc(fp);
            }

            qus[i] = '\0';

            ch = fgetc(fp);

            for (i = 0; !(isspace(ch)); i++) {
                ans[i] = ch;
                ch = fgetc(fp);
            }

            ans[i] = '\0';
            printf("問題= %s 解答= %s\n", qus, ans);
        }

ending:
        ending();
    }

    system("PAUSE");
    return (0);
}
