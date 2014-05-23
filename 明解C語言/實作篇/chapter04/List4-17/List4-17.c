/*
    將單字從檔案讀入並顯示
*/

#include  <ctype.h>
#include  <stdio.h>
#include  <string.h>

#define Q_NO        3               /* 問題個數 */

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
        char  qus[20] = "";         /* 問題用字串 */
        char  ans[20] = "";         /* 解答用字串 */

        for (q = 0; q < Q_NO; q++) {
            int  i;

            strcpy(ans, "");        /* 沒有照預期的動作? */
            strcpy(qus, "");        /*        "         */

            ch = fgetc(fp);

            if (ch == EOF) {
                goto ending;
            }

            for (i = 0; !(isspace(ch)); i++) {
                qus[i]   = ch;
                qus[i + 1] = '\0';      /* 後來才代入 */
                ch = fgetc(fp);
            }

            ch = fgetc(fp);

            for (i = 0; !(isspace(ch)); i++) {
                ans[i]   = ch;
                ans[i + 1] = '\0';      /* 後來才代入 */
                ch = fgetc(fp);
            }

            printf("問題=%s 解答=%s\n", qus, ans);
        }

ending:
        ending();
    }

    system("PAUSE");
    return (0);
}
