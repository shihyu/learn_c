# VLA

變長陣列(VLA)的原型寫法、聲明位置及變長陣列的本質，vla原型變長陣列（variable-length array）是C語言C99標準中新增加的內容，**此處所謂的「變」並非在說該類型的陣列在創建後可修改大小，變長陣列的大小在創建後也是不能修改的。那為什麼此處稱為「變長」呢，是因為變長陣列的維可以用變數來指定。這一點特性彌補了C99之前的變數維度只能用常量或常量表達式指定的不足。**


變長陣列是有一些限制的，變長陣列只可在函數內部或作為函數參數聲明。並且在聲明是不能初始化。

來看一個例子：

編寫一個程序，初始化一個3x5的二維double陣列，並利用一個基於變長陣列的函數把該陣列複製到另一個二維陣列。還要編寫一個基於變長陣列的函數來顯示兩個陣列的內容。這兩個函數應該能夠處理任意的NxM陣列。


```cpp
#include <stdio.h>

void copy(int row, int col, double arr[][col], double tar[row][col]);
void show(int, int, double arr[*][*]);

int main(void)
{

    double num[3][5] = {
        {2.3, 1.2, 5.2, 6.1, 1.1},
        {4.2, 3.2, 6.2, 1.7, 7.4},
        {8.5, 6.2, 4.7, 2.8, 2.1}
    };

    double rain[5][12] = {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    double tar[3][5] = {0};
    double tar2[5][12] = {0};

    copy(3, 5, num, tar);
    show(3, 5, tar);

    copy(5, 12, rain, tar2);
    show(5, 12, tar2);

    return 0;
}

void copy(int row, int col, double arr[][col], double tar[row][col])
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            tar[i][j] = arr[i][j];
        }
    }
}

void show(int row, int col, double arr[row][col])
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%.1f", arr[i][j]);

            if (j != col - 1) {
                printf(", ");
            }
        }

        printf("\n");
    }

    printf("------------------------------

```
在這個例子中，給定兩個二維陣列，一個3X5陣列和一個5X12陣列，而例子中這兩個陣列用同一個函數處理拷貝或用同一個函數顯示。

其中用於顯示的函數：

```cpp
void show(int row,int col,double arr[row][col])
```
是一個變長陣列的定義方法，將代表維的整數聲明在使用該維的變長陣列之前。因為在原型中可以省略變數名，所以原型可以寫為：

```cpp
void show(int,int,double arr[*][*])
```

