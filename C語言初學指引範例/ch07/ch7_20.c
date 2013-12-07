/***************************
    檔名:ch7_20.c
    功能:設計樂透開獎遊戲
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SeqSearch(int Target, int* arr, int arr_index);
void generate_lotto(int* spec_num, int* arr, int arr_index);

/**************循序搜尋**************/
int SeqSearch(int Target, int* arr, int arr_index) {
    int i;

    for (i = 0; i < arr_index; i++)
        if (Target == arr[i]) {  /*  找到了  */
            return i;
        }

    return -1;                  /*  完全找不到  */
}

/**************產生樂透號碼**************/
void generate_lotto(int* spec_num, int* arr, int arr_index) {
    int i, generate_num;
    srand((unsigned) time(NULL));

    for (i = 0; i < arr_index; i++) {
        generate_num = rand() % 42 + 1;

        while (SeqSearch(generate_num, arr, i + 1) != -1) { /*  是否重複  */
            generate_num = rand() % 42 + 1;
        }

        arr[i] = generate_num;
    }

    generate_num = rand() % 42 + 1;

    while (SeqSearch(generate_num, arr, i) != -1) { /*  特別號是否與其他號碼重複  */
        generate_num = rand() % 42 + 1;
    }

    *spec_num = generate_num;
}

/**************main()**************/
void main(void) {
    int lotto[6], i, special;
    generate_lotto(&special, lotto, 6);
    printf("樂透號碼如下.....\n");

    for (i = 0; i < 6; i++) {
        printf("%d\t", lotto[i]);
    }

    printf("\n");
    printf("特別號:%d\n", special);
    /*  system("pause");  */
}
