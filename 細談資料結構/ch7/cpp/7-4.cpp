/*=========================================================

       7-4節 合併動作

          merge()               合併
          a[M]                  欲合併之資料1
          b[N]                  欲合併之資料2
          c[M+N]                合併的結果

  =========================================================
*/

#include <iostream.h>

#define MAX_INT 32767
#define M   5
#define N   7
void  merge(int [], int [], int , int [], int);

void main(void) {
    int a[M + 1] = {9, 12, 17, 21, 37, MAX_INT}, i;
    int b[N + 1] = {3, 11, 20, 55, 67, 71, 89, MAX_INT};
    int c[M + N];
    cout << "陣列 A :" << endl;

    for (i = 0; i < M ; i++) {
        cout << " " << a[i];
    }

    cout << endl << "陣列 B :" << endl;

    for (i = 0; i < N ; i++) {
        cout << " " << b[i];
    }

    merge(c, a, M, b, N);
    cout << endl << "合併成 陣列 C :" << endl;

    for (i = 0; i < M + N ; i++) {
        cout << " " << c[i];
    }

    cout << endl;
}
void  merge(int c[], int a[], int m, int b[], int n) {
    int i, j, k;
    i = j = 0 ;
    a[m] = b[n] = MAX_INT;

    for (k = 0; k < m + n ; k++) {
        c[k] = (a[i] <= b[j]) ? a[i++] : b[j++] ;
    }
}
