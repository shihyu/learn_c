/************************************************************
    檔名:ch7_24.c
    功能:使用命令列參數決定開出的球數,並回傳執行是否正確
 ************************************************************/

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
int main(int argc, char* argv[]) {
    int lotto[42], i, special, ball_qty = 6;

    if (argc > 1) {
        ball_qty = atoi(argv[1]);

        if ((ball_qty <= 0) || (ball_qty > 41)) {
            return 1;    /*  參數錯誤,例如輸入球數為字串而非數字1~41  */
        }
    }

    generate_lotto(&special, lotto, ball_qty);
    printf("樂透號碼如下.....\n");

    for (i = 0; i < ball_qty; i++) {
        if ((i % 6 == 0) && (i != 0)) {
            printf("\n");
        }

        printf("%d\t", lotto[i]);
    }

    printf("\n");
    printf("特別號:%d\n", special);
    return 0;
    /*  system("pause");  */
}
