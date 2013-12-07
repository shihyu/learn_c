/***************************
    檔名:ch7_04.c
    功能:函式應用
 ***************************/

#include <stdio.h>
#include <stdlib.h>

long int factorial(int p); /* 函式宣告 */
long int factorial(int p) { /* 函式定義 */
    int count;
    long int result = 1;

    for (count = 1; count <= p; count++) {
        result = result * count;
    }

    return result;
}

void main(void) {
    int m, n;
    long int ans;
    long int temp[3];
    printf("求排列組合C(m,n)\n");
    printf("m = ");
    scanf("%d", &m);
    printf("n = ");
    scanf("%d", &n);
    temp[0] = factorial(m);      /*  計算 m! 的值     */
    temp[1] = factorial(n);      /*  計算 n! 的值     */
    temp[2] = factorial(m - n);  /*  計算 (m-n)! 的值 */
    ans = (temp[0]) / (temp[1] * temp[2]); /* C(m,n) = (m!)/(n!*(m-n)!) */
    printf("C(%d,%d) = %d\n", m, n, ans);
    /*  system("pause");  */
}
