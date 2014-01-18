/*=========================================================

      4-8節 遞迴 :

      fact()    階層函式


  =========================================================
*/
#include<stdio.h>
int fact(int);

void main(void) {
    int n;
    printf("Please input a number less than 12 =>");
    scanf("%d", &n);                    /*讀入數字*/

    if (n > 12) {
        printf("The number is to large ...");
    } else {
        printf("%d! = %d \n ", n, fact(n));
    }
}

int fact(int n) {
    int  f;

    if (n == 0) {
        return (1);    //終止條件
    }

    f = fact(n - 1);            //遞迴呼叫
    return (n * f);
}
