/*=========================================================

     例題 1-12

        factorial()       求 n 階乘
  =========================================================
*/

#include <stdio.h>

int factorial(int);

void main(void) {
    int n;
    int answer;
    printf("\nPlease input a number less than 12 =>");
    scanf("%d", &n);                    /*讀入數字*/

    if (n > 12) {         /*因大於12之階乘會超出 int 所能表示之範圍*/
        printf("The answer will be too large for an integer.\n");
    } else if (n < 0) {                      /*小於零之數不合法*/
        printf("Input error,number must > 0");
    } else {
        answer = factorial(n);
        printf("%d! = %d\n ", n, answer);
    }
}

/*階乘計算函式*/
int factorial(int n) {
    int i;
    int result;
    result = 1;
    i = 1;

    while (i <= n) {
        result = result * i;
        i++;
    }

    return result;
}
