/**************************************
     檔名:useful_algorithm.h
     撰寫人:jhchen
     用途:眾多資料結構相關的演算法
     版本:v1.0 (for C language)
 **************************************/

/***************函式宣告區*************/
void BubbleSort(int* arr, int arr_index);
int SeqSearch(int Target, int* arr, int arr_index);
int BinarySearch(int Target, int* arr, int arr_index);


/*************************氣泡排序****************************
   語法：  void BubbleSort(int *arr,int arr_index);
   引數：  arr[ ]為工作陣列，arr_index為工作陣列大小。
   回傳值：無。
   註解：  函式執行完畢，arr[]的元素會依照由小而大排序
 *************************************************************/
void BubbleSort(int* arr, int arr_index) {
    int k, times, i, temp;
    k = arr_index - 1;

    while (k != 0) {
        times = 0;

        for (i = 0; i <= k - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp; /* [i]與[i+1]互換 */
                times = i;
            }
        }

        k = times;
    }
}


/*************************循序搜尋****************************
   語法：  int SeqSearch(int Target,int *arr,int arr_index);
   引數：  Target為尋找目標。
           arr[ ]為工作陣列，arr_index為工作陣列大小。
   回傳值：若Target位於arr[ ]陣列中，則回傳索引值。
           若Target不位於arr[ ]陣列中，則回傳-1。
 *************************************************************/
int SeqSearch(int Target, int* arr, int arr_index) {
    int i;

    for (i = 0; i < arr_index; i++)
        if (Target == arr[i]) {  /*  找到了  */
            return i;
        }

    return -1;                  /*  完全找不到  */
}


/*************************二分搜尋****************************
   語法：  int BinarySearch(int Target,int *arr,int arr_index)
   引數：  Target為尋找目標。
           arr[ ]為已排序的工作陣列，arr_index為工作陣列大小。
   回傳值：若Target位於arr[ ]陣列中，則回傳索引值。
           若Target不位於arr[ ]陣列中，則回傳-1。
 *************************************************************/
int BinarySearch(int Target, int* arr, int arr_index) {
    int Low, Upper, m;
    Low = 0;
    Upper = arr_index - 1;

    while (Low <= Upper) {
        m = (Low + Upper) / 2; /* 計算中間位置 */

        if (arr[m] == Target) { /* 找到了 */
            return m;
        } else {
            if (arr[m] > Target) { /* Target位於上半部 */
                Upper = m - 1;
            } else {           /* Target位於下半部 */
                Low = m + 1;
            }
        }
    }

    return -1;
}
