/*=========================================================

     例 1-9,1-10,1-11

       迴圈計數
  =========================================================
*/

#include <stdio.h>

void main(void) {
    int i, j, n, result ;
    printf("Please input a positive integer N =>");
    scanf("%d", &n);                    /*讀入數字*/
    /* 單層迴圈 */
    result = 0 ;

    for (i = 1 ; i <= n ; i++) {
        result = result + 1;
    }

    printf("\n result = %d ( = %d  )  ", result, n);
    /* 單層迴圈, 內圈固定次數*/
    result = 0 ;

    for (i = 1; i <= n ; i ++)
        for (j = 1 ; j < n ; j++) {
            result = result + 1 ;
        }

    printf("\n result = %d ( = %d * ( %d - 1 ) ) ", result, n, n);
    /* 單層迴圈, 內圈固定次數*/
    result = 0 ;

    for (i = 1 ; i <= n ; i++)
        for (j = i + 1 ; j <= n ; j++) {
            result = result + 1;
        }

    printf("\n result = %d ( = %d * ( %d - 1 ) / 2 ) \n", result, n, n);
}

