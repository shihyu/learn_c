/*=========================================================

     例 1-12

        factorial()       求 N 階乘
  =========================================================
*/

#include <iostream.h>

int factor(int);

void main(void) {
    int n;
    int answer;
    cout << "Please input a number less than 12 => ";
    cin >> n;                     //讀入數字

    if (n > 12) {               //因大於12之階乘超出 int 所能表示之範圍
        cout << "The answer will be too large for a long integer.\n";
    } else if (n < 0) {                      //小於零之數不合法
        cout << "Input error,number must > 0";
    } else {
        answer = factor(n);
        cout << answer << "! = " << answer << "\n ";
    }
}

//階乘計算函式
int factor(int n) {
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
