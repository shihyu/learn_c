/*=============================================
    1-D Array
    ArrayInsert(), ArrayDelete(), ArrayCopy()
===============================================*/

#include <iostream.h>
#include <stdlib.h>

#define N   8
void ArrayInsert(int [], int, int, int);
void ArrayDelete(int [], int , int);
void ArrayCopy(int [], int [], int);
void PrintArray(int [], int);
void WaitMessage(void);

void main(void) {
    int list[N] = {5, 25, 11, 26, 39, 18, 120, 50}, target_list[N];
    int value, position;
    /* Test Array Insert */
    PrintArray(list, N);
    cout << "\n Please Input Value and Insert Position, like 67 3 => ";
    cin >> value >> position;
    cout << "\n Before Insert " << value << " into index " << position;
    PrintArray(list, N);
    ArrayInsert(list, N, position, value);
    cout << "\n After Insert " << value << "into index " << position;
    PrintArray(list, N);
    /* Test Array Insert */
    cout << "\n Please Input Delete Position, like 3 =>";
    cin >> position;
    cout << "\n Before Delete index " << position;
    PrintArray(list, N);
    ArrayDelete(list, N, position);
    cout << "\n After Delete index " << position;
    PrintArray(list, N);
    /* Test Array Copy */
    WaitMessage();
    cout << "\n === Testing Array Copy ===";
    cout << "\n The contents of list ";
    PrintArray(list, N);
    ArrayCopy(target_list, list, N);
    cout << "\n target_list After Copied from list";
    PrintArray(target_list, N);
}

/* 在list陣列上有n個元素, 將value插入位置i  */
void ArrayInsert(int list[], int n, int i, int value) {
    int  counter  ;

    if (i < 0 || i >= n) {
        return;
    }

    for (counter = n - 1; counter > i ; counter--) {
        list[counter] = list[counter - 1] ;
    }

    list[i] = value ;
}
/* 在list陣列上, 有n個元素, 將刪除位置i的元素  */
void ArrayDelete(int list[], int n, int i) {
    int  counter  ;

    if (i < 0 || i >= n) {
        return;
    }

    for (counter = i ; counter < n - 1 ; counter++) {
        list[counter] = list[counter + 1] ;
    }

    list[n - 1] = 0 ;
}
/* 將list2陣列複製到list1陣列, 兩個陣列都有n個元素  */
void ArrayCopy(int list1[], int list2[], int n) {
    int  counter  ;

    for (counter = 0 ; counter < n ; counter++) {
        list1[counter] = list2[counter] ;
    }
}
/* 印出將list陣列內容, list陣列有n個元素  */
void PrintArray(int list[], int n) {
    int  counter  ;

    for (counter = 0 ; counter < n ; counter++) {
        cout << "\n list[" << counter << "]= " << list[counter] ;
    }

    cout << "\n";
}
void WaitMessage(void) {
    int c;
    cout << "\n Press Any Key ( Except Space ) + 'Enter' To Continue...\n" ;
    cin >> c;
    system("cls");
}
