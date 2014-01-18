/*=========================================================

     4-8 節  例4.6 : 遞迴 : 河內塔問題

      hanoi()   把 n 個盤子,從 form 柱,經由 by 柱,搬往 to 柱

  =========================================================
*/
#include <stdio.h>
#include <stdlib.h>
void hanoi(int , char , char , char);

void main(void) {
    int n;
    printf("Please input number =>");
    scanf("%d", &n);                    /*讀入數字*/

    if (n > 20) {
        printf("The calucation time will be too long to wait...");
        exit(1);
    }

    if (n < 0) {            /*小於零之數不合法*/
        printf("input error,number must > 0");
        exit(1);
    }

    hanoi(n, 'A', 'B', 'C');
    printf("結束\n");
}

/*把 n 個盤子,從 form 柱,經由 by 柱,搬往 to 柱*/
void hanoi(int n, char from, char by, char to) {
    if (n > 0) {
        hanoi(n - 1, from, to, by);
        printf("move no. %d  disk from '%c' to '%c' \n", n, from, to);
        hanoi(n - 1, by, from, to);
    }
}
