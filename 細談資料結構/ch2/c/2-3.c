/*=========================================================
    第二章

      2-D Array

          MAX_SIZE          最大列數或行數
          ArrTrans()        陣列轉置
          A1[rows][cols]    存放待轉置陣列內容
          B1[cols][rows]    存放轉置後陣列內容
          rows              列數
          cols              行數
          A2[rows][cols]    存放待相加陣列內容
          B2[rows][cols]    存放待相加陣列內容
          C2[rows][cols]    存放陣列相加後內容
          A3[m][n]          存放待相乘陣列內容
          B3[n][t]          存放待相乘陣列內容
          C3[m][t]          存放陣列相乘後內容

  =========================================================
*/

#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 100

void ArrTrans(int [][MAX_SIZE], int [][MAX_SIZE], int, int);
void ArrAdd(int [][MAX_SIZE], int [][MAX_SIZE], int [][MAX_SIZE], int, int);
void ArrMul(int [][MAX_SIZE], int [][MAX_SIZE], int [][MAX_SIZE], int, int, int);
void PrintArr(int [][MAX_SIZE], int, int);
void main(void) {
    int rows = 4, cols = 3, m = 3, n = 2, t = 4;
    int A1[MAX_SIZE][MAX_SIZE] = {  {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    int B1[MAX_SIZE][MAX_SIZE];
    int A2[MAX_SIZE][MAX_SIZE] = {  {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    int B2[MAX_SIZE][MAX_SIZE] = {  {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {9, 10, 11}
    };
    int C2[MAX_SIZE][MAX_SIZE];
    int A3[MAX_SIZE][MAX_SIZE] = {{1, 2},
        {4, 5},
        {3, 6}
    };
    int B3[MAX_SIZE][MAX_SIZE] = {{0, 1, 1, 2},
        {4, 0, -1, 3}
    };
    int C3[MAX_SIZE][MAX_SIZE];
    /* Test Array Transposition */
    printf("\nPress any key to test Array Transpose (按任一鍵執行矩陣轉置) ");
    getch();
    ArrTrans(A1, B1, rows, cols);
    printf("\n矩陣A =>\n");
    PrintArr(A1, rows, cols);
    printf("矩陣A 的轉置 矩陣B=>\n");
    PrintArr(B1, cols, rows);
    /* Test Array Addition */
    printf("\nPress any key to test Array Addition (按任一鍵執行矩陣相加) ");
    getch();
    ArrAdd(A2, B2, C2, rows, cols);
    printf("\n矩陣A =>\n");
    PrintArr(A2, rows, cols);
    printf("加矩陣B =>\n");
    PrintArr(B2, rows, cols);
    printf("等於矩陣C =>\n");
    PrintArr(C2, rows, cols);
    /* Test Array Multiplication */
    printf("\nPress any key to test Array Multiplication (按任一鍵執行矩陣相乘) ");
    getch();
    ArrMul(A3, B3, C3, m, n, t);
    printf("\n矩陣A =>\n");
    PrintArr(A3, m, n);
    printf("乘矩陣B =>\n");
    PrintArr(B3, n, t);
    printf("等於矩陣C =>\n");
    PrintArr(C3, m, t);
}

void ArrTrans(int A[][MAX_SIZE], int B[][MAX_SIZE], int rows, int cols) {
    int i, j;

    for (i = 0 ; i < rows ; i++)
        for (j = 0 ; j < cols ; j++) {
            B[j][i] = A[i][j];
        }
}
void ArrAdd(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows ; i++)
        for (j = 0; j < cols ; j++) {
            C[i][j] = A[i][j] + B[i][j] ;
        }
}

void ArrMul(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int m, int n, int t) {
    int i, j, k ;

    for (i = 0; i < m; i++)
        for (j = 0; j < t; j++) {
            C[i][j] = 0 ;

            for (k = 0; k < n; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j] ;
            }
        }
}

void PrintArr(int A[][MAX_SIZE], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", A[i][j]);
        }

        printf("\n");
    }
}
