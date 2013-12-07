#include <stdio.h>

void main(void) {
    int A[5] = {5, 6, 7, 8, 9};
    char* p = (char*)A;
    int temp;
    /*************加入程式碼,使得temp內容為A[3]的值****************/
    temp = *p;
    printf("A[3]=%d\n", temp);
}
