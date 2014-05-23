/*
  設定主控台畫面的字元色．背景色--"SETCOLOR.c"
*/

#include  <ctype.h>
#include  <stdio.h>
#include  <stdlib.h>

#include  "display.h"

/*--- 顏色的字串 ---*/
char* color_str[] = {
    "BLACK", "BLUE", "RED", "GREEN", "MAGENTA", "CYAN", "YELLOW", "WHITE",
    "GRAY", "LIGHT_BLUE", "LIGHT_RED", "LIGHT_GREEN", "LIGHT_MAGENTA",
    "LIGHT_CYAN", "LIGHT_YELLOW", "BLIGHT_WHITE"
};

/*--- 比較字串(不區分大寫小寫) ---*/
int strcmpx(const char* s1, const char* s2) {
    while (toupper(*s1) == toupper(*s2)) {
        if (*s1 == '\0') {          /* 相等 */
            return (0);
        }

        s1++;
        s2++;
    }

    return (toupper((unsigned char) * s1) - toupper((unsigned char) * s2));
}

/*--- 將顏色的字串轉換成字碼 ---*/
int get_color(char* str) {
    int  i;

    for (i = 0; i < sizeof(color_str) / sizeof(color_str[0]); i++)
        if (!strcmpx(str, color_str[i])) {
            return (i);
        }

    return (-1);                /* 無對應顏色 */
}

/*--- 顯示錯誤訊息和使用方法並強制結束 ---*/
void error(int code) {
    switch (code) {
    case 1:
        fprintf(stderr, "請指定字元色．背景色。\n");
        break;

    case 2:
        fprintf(stderr, "字元色的指定不正確。\n");
        break;

    case 3:
        fprintf(stderr, "背景色的指定不正確。\n");
        break;
    }

    fprintf(stderr, "---------------------------------------\n");
    fprintf(stderr, "SETCOLOR字元色「背景色」\n");
    fprintf(stderr, "---------------------------------------\n");
    fprintf(stderr, "字元色請指定以下顯示的16色\n");
    fprintf(stderr, "背景色請指定左側的8色\n");
    fprintf(stderr, "若將背景色省略則會使用黑色\n");
    fprintf(stderr, "---------------------------------------\n");
    fprintf(stderr, "BLACK        GRAY\n");
    fprintf(stderr, "BLUE         LIGHT_BLUE\n");
    fprintf(stderr, "RED          LIGHT_RED\n");
    fprintf(stderr, "GREEN        LIGHT_GREEN\n");
    fprintf(stderr, "MAGENTA      LIGHT_MAGENTA\n");
    fprintf(stderr, "CYAN         LIGHT_CYAN\n");
    fprintf(stderr, "YELLOW       LIGHT_YELLOW\n");
    fprintf(stderr, "WHITE        BLIGHT_WHITE\n");

    exit(1);                    /* 強制結束 */
}

int main(int argc, char* argv[]) {
    int  fg, bg = BLACK;        /* 字元色/背景色 */

    if (argc < 2) {             /* 字元色．背景色未被指定 */
        error(1);
    }

    if (argc >= 2)
        if ((fg = get_color(argv[1])) == -1) {
            error(2);
        }

    if (argc >= 3)
        if ((bg = get_color(argv[2])) == -1) {
            error(3);
        }

    colorx(fg, bg);

    return (0);
}
