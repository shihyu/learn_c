/*=========================================================

      4-8節 遞迴 : factor

      fact()    階層函式


  =========================================================
*/
#include<iostream.h>
int fact(int);

void main(void) {
    int n;
    cout << "Please input a number less than 12 => ";
    cin >> n;                     //讀入數字

    if (n > 12) {
        cout << "The number is to large ...";
    } else {
        cout << n << "! = " << fact(n) << " \n ";
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
