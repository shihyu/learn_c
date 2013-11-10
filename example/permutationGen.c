#include <stdio.h>
#include <string.h>

void swap(char a[], int n, int m) {
    char t = a[n];
    a[n] = a[m];
    a[m] = t;
}

void permutation(char a[], int k, int n) {
    /*
     * 求a[]n个元素的排列
     * k，当前已经排列好的元素的个数
     */
    int i;

    if (k == n - 1) {
        for (i = 0; i < n; i++) {
            printf("%c ",a[i]);
        }
        printf("\n");
    } else {
        for (i = k; i < n; i++) {
            swap(a, i, k);
            permutation(a, k + 1, n);
            swap(a, i, k);
        }
    }
}

int main(int argc, char *argv[])
{
    char a[3] = {'a','b','c'};
    permutation(a, 0, 3);
    return 0;
}

