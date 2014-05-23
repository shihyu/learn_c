/*
    畫面控制(脫逸字元/Win32API)標頭檔--"display.h"
*/

enum {  BLACK,              /* 黑色 */
        BLUE,               /* 藍色 */
        RED,                /* 紅色 */
        GREEN,              /* 綠色 */
        MAGENTA,            /* 紅紫 */
        CYAN,               /* 水色 */
        YELLOW,             /* 黃色 */
        WHITE,              /* 白色 */
        GRAY,               /* 灰色 */
        LIGHT_BLUE,         /* 亮藍色 */
        LIGHT_RED,          /* 亮紅色 */
        LIGHT_GREEN,        /* 亮綠色 */
        LIGHT_MAGENTA,      /* 亮紅紫色 */
        LIGHT_CYAN,         /* 亮水色 */
        LIGHT_YELLOW,       /* 亮黃色 */
        BLIGHT_WHITE        /* 亮白色 */
     };

/*--- 畫面消去 ---*/
void cls(void);

/*--- 將游標位置設至(__x, __y) ---*/
void locate(int __x, int __y);

/*--- 將字元色設為__fg，將背景色設為__bg ---*/
void colorx(int __fg, int __bg);

/*--- 將字元色設為__col ---*/
void color(int __col);
