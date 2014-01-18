/*=========================================================

       8-2-1節 循序搜尋法

          Sqn_Srch()            循序搜尋函式
          a[ARR_NUM]            欲搜尋之資料
          ARR_NUM               欲搜尋之資料數目(陣列大小)

  =========================================================
*/

#include <iostream.h>

#define ARR_NUM 10
int Sequential_Search(int [], int , int);
void PrintArray(int [], int);

void main(void) {
    int a[ARR_NUM] = {39, 81, 6, 78, 69, 41, 52, 33, 55, 77};
    int data, locate;
    cout << "陣列內容:";
    PrintArray(a, ARR_NUM);
    cout << endl << "請輸入欲搜尋之資料內容 => ";
    cin >> data;

    if ((locate = Sequential_Search(a, ARR_NUM, data)) == -1) {
        cout << "找不到資料!!!";
    } else {
        cout << "找到資料 " << data << " 於第 " << locate << " 個位置 (由0算起)";
    }

    cout << endl;
}

/*在a[0..n-1]陣列尋找鍵值key的元素,並傳回位置*/
int Sequential_Search(int a[], int n, int key) {
    int i;

    for (i = 0 ; i < n; i++)
        if (a[i] == key) {
            return (i);    /*成功傳回位置*/
        }

    return (-1);         /*失敗傳回*/
}

void PrintArray(int a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        cout << " " << a[i];
    }
}
