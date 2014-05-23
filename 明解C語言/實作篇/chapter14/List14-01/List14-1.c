/*
  使用脫逸字元的畫面控制
*/

#include <stdio.h>

enum { BLACK, BLUE, RED, GREEN, MAGENTA, CYAN, YELLOW, WHITE,
       GRAY,  LIGHT_BLUE, LIGHT_RED, LIGHT_GREEN, LIGHT_MAGENTA,
       LIGHT_CYAN, LIGHT_YELLOW, BLIGHT_WHITE
     };

/*--- 畫面消除 ---*/
void cls(void) {
    printf("\x1B[2J");
}

/*--- 將游標位置設定於(x,y) ---*/
void locate(int x, int y) {
    printf("\x1B[%d;%dH", y, x);
}

/*--- 將字元色設為fg，將背景色設為bg ---*/
void colorx(int fg, int bg) {
    int  col[] = {30, 34, 31, 32, 35, 36, 33, 37};

    printf("\x1B[0;");

    if (fg > WHITE) {
        printf("1;");    /* 高亮度 */
    }

    printf("%d;%dm", col[fg % 8], col[bg % 8] + 10);

}

/*--- 將字元色設為col ---*/
void color(int col) {
    colorx(col, BLACK);                 /* 字元色為col，背景色為黑 */
}

int main(void) {
    cls();          /* 畫面消去 */

    locate(3, 2);
    color(WHITE);
    printf("中文");

    locate(3, 4);
    color(BLUE);
    printf("英文");

    locate(3, 6);
    colorx(BLACK, BLUE);
    printf("範例字元");

    locate(3, 8);
    colorx(BLUE, WHITE);
    printf("Sample text");

    color(WHITE);

    return (0);
}
