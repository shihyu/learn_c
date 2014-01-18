/*=========================================================

     4-8節 例 4.7  遞迴

      二項式係數

  =========================================================
*/
#include<iostream.h>
int  C(int n, int k);

void main(void) {
    int n, k;
    cout << "Please input integers n and k (n>k>0) =>";
    cin >> n >> k;                     /*讀入數字*/

    if ((n <= 0) || (k < 0) || (n < k)) {
        cout << "Wrong Input" << endl;
    } else {
        cout << "C(" << n << "," << k << ") = " << C(n, k) << endl;
    }
}

int  C(int n, int k) {
    if (k == 0 || n == k) {
        return 1;    //終止條件
    }

    return (C(n - 1, k) + C(n - 1, k - 1)); //遞迴呼叫
}

