/***************************
    檔名:ch5_19.c
    功能:do-while迴圈的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char InputChar;
    /* ...........遊戲程式撰寫處........... */
    printf("Game Over...\n");

    do {
        printf("Play Again?(y/n)");
        InputChar = getchar();
        getchar();
    } while ((InputChar != 'y') && (InputChar != 'n'));

    /*  system("pause");  */
}
