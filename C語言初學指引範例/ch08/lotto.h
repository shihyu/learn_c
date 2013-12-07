/**************************************
     檔名:lotto.h
     撰寫人:jhchen
     用途:提供樂透遊戲相關函式
     版本:v1.0 (for C language)
 **************************************/

#include <stdlib.h>
#include <time.h>
#include "./useful_algorithm.h"

/***************函式宣告區*************/
int generate_lotto(int* spec_num, int* arr, int arr_index);
int generate_lotto_sort(int* spec_num, int* arr, int arr_index);


/***************************產生樂透號碼(未排序)************************
   語法：  int generate_lotto(int *spec_num,int *arr,int arr_index);
   功能：  會從1~42號中，開出未排序的arr_index個球，外加一個特別號。
   引數：  arr[ ]為工作陣列，arr_index為工作陣列大小。
           arr_index為開球數目，必須介於1~41。
           spec_num為特別號存放變數(使用傳指標呼叫)
   回傳值：0為錯誤,1為執行正確。
 ***********************************************************************/
int generate_lotto(int* spec_num, int* arr, int arr_index) {
    int i, generate_num;
    srand((unsigned) time(NULL));

    if (!((arr_index >= 1) && (arr_index <= 41))) {
        return 0;    /* 引數錯誤,例如輸入球數為字串而非數字1~41 */
    }

    for (i = 0; i < arr_index; i++) {
        generate_num = rand() % 42 + 1;

        while (SeqSearch(generate_num, arr, i + 1) != -1) { /* 是否重複 */
            generate_num = rand() % 42 + 1;
        }

        arr[i] = generate_num;
    }

    generate_num = rand() % 42 + 1;

    while (SeqSearch(generate_num, arr, i) != -1) { /* 特別號是否與其他號碼重複 */
        generate_num = rand() % 42 + 1;
    }

    *spec_num = generate_num;
    return 1;
}

/***************************產生樂透號碼(已排序)***************************
   語法：  int generate_lotto_sort(int *spec_num,int *arr,int arr_index);
   功能：  會從1~42號中，開出已排序的arr_index個球，外加一個特別號。
   引數：  arr[ ]為工作陣列，arr_index為工作陣列大小
           arr_index為開球數目，必須介於1~41。
           spec_num為特別號存放變數(使用傳指標呼叫)
   回傳值：0為錯誤,1為執行正確。
 **************************************************************************/
int generate_lotto_sort(int* spec_num, int* arr, int arr_index) {
    if (generate_lotto(spec_num, arr, arr_index)) {
        BubbleSort(arr, arr_index);
    } else {
        return 0;
    }

    return 1;
}
