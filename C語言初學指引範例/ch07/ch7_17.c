/***************************
    檔名:ch7_17.c
    功能:傳址呼叫傳遞參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_lotto(int* arr, int arr_index) {
    int i;
    srand((unsigned) time(NULL));
    printf("樂透號碼開獎中.....\n");

    for (i = 0; i < arr_index; i++) {
        arr[i] = rand() % 42 + 1;
        printf("第%d個號碼為%d\n", i + 1, arr[i]);
    }
}

void main(void) {
    int lotto[6], i;
    generate_lotto(lotto, 6);
    printf("樂透號碼如下.....\n");

    for (i = 0; i < 6; i++) {
        printf("%d\t", lotto[i]);
    }

    printf("\n");
    /*  system("pause");  */
}
