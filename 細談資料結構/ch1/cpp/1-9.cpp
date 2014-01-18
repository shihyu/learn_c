/*=========================================================

     例 1-9,1-10,1-11

       迴圈計數
  =========================================================
*/

#include <iostream.h>

void main(void) {
    int i, j, n, result ;
    cout << "Please input a positive integer N => ";
    cin >> n;                     //讀入數字
    // 單層迴圈
    result = 0 ;

    for (i = 1 ; i <= n ; i++) {
        result = result + 1;
    }

    cout << "\n result = " << result << " ( = " << n << "  )  ";
    // 單層迴圈, 內圈固定次數
    result = 0 ;

    for (i = 1; i <= n ; i ++)
        for (j = 1 ; j < n ; j++) {
            result = result + 1 ;
        }

    cout << "\n result = " << result << " ( = " << n << " * ( " << n << " - 1 ";
    // 單層迴圈, 內圈固定次數
    result = 0 ;

    for (i = 1 ; i <= n ; i++)
        for (j = i + 1 ; j <= n ; j++) {
            result = result + 1;
        }

    cout << "\n result = " << result << " ( = " << n << " * ( " << n << " - 1 ) / 2 ) \n";
}

