/*=========================================================

     4-8節 例 4.5  遞迴

      Fib()     Fibanacci數列函式

  =========================================================
*/
#include<iostream.h>
int   Fib(int);

void main(void) {
    int n;
    cout << "Please input an integer  =>";
    cin >> n;                     /*讀入數字*/

    if (n < 0) {
        cout << "Wrong Input";
    } else {
        cout << "Fib(" << n << ") = " << Fib(n) << endl;
    }
}

int   Fib(int n) {
    int   i, j;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    i = Fib(n - 1);
    j = Fib(n - 2);
    return (i + j);
}
