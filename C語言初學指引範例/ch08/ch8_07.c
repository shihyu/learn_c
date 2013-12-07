/*******************************
    檔名:ch8_07.c
    功能:傳指標呼叫實作swap( )
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(void) {
    int m = 20, n = 60;
    printf("變換前(m,n)=(%d,%d)\n", m, n);
    swap(&m, &n);
    printf("變換後(m,n)=(%d,%d)\n", m, n);
    /*  system("pause");  */
}
