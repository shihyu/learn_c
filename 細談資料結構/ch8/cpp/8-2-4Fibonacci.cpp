/*=========================================================

       8-2-4 費氏搜尋法

          Fib_Search()          費氏搜尋函式
          a[ARR_NUM]            欲搜尋之資料
          ARR_NUM               欲搜尋之資料數目(陣列大小)

  =========================================================
*/

#include <iostream.h>

#define MAX_NUM 12
#define Fib_NUM 20
int Fib_Search(int [], int , int , int);
void PrintArray(int [], int);
int F[Fib_NUM];
void Init_Fib(int []);
int Find_Point(int [], int);

void main(void) {
    int a[MAX_NUM] = {6, 33, 39, 41, 52, 55, 69, 77, 78, 81};
    int n = 10 ;  //real size of data
    int data, locate, k;
    Init_Fib(F);
    k = Find_Point(F, n);
    PrintArray(a, n);
    cout << endl << "請輸入欲搜尋之資料內容 => ";
    cin >> data;

    if ((locate = Fib_Search(a, n, data, k)) == -1) {
        cout << "找不到資料!!!";
    } else {
        cout << "找到資料 " << data << " 於第 " << locate << " 個位置 ( 由 0 算起)";
    }

    cout << endl;
}

void Init_Fib(int F[]) {
    int i;
    F[0] = 0;
    F[1] = 1;

    for (i = 2; i <= Fib_NUM ; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

int Find_Point(int F[], int n) {
    int k;

    for (k = 0; k < Fib_NUM; k++)
        if ((n > F[k] - 1) && (n <= F[k + 1] - 1)) {
            break;
        }

    return k + 1;
}

/*在a[0..n-1]陣列尋找鍵值key的元素,並傳回位置 ,使用binary Search*/
int  Fib_Search(int a[], int n, int key, int k) { //假設已知F[k-1]-1 < n   F[k]-1
    int l = 0, r = n - 1, m, i;

    for (i = n; i < F[k] - 1; i++) { //dummy key
        a[i] = a[n - 1];
    }

    while (l <= r) {
        m = l + F[k - 1] - 1 ;      //沒有乘法或除法

        if (key == a[m]) {
            if (m < n) {         //not dummy
                return (m);    //找到,傳回位置
            } else {
                return (n - 1);
            }
        }

        if (key < a[m]) {       //左半部,改變右限
            r = m - 1;
            k = k - 1 ;
        } else {                //右半部,改變左限
            l = m + 1;
            k = k - 2 ;
        }
    }

    return (-1);            //失敗傳回-1
}


void  PrintArray(int a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        cout << " " << a[i];
    }
}

