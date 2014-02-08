#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 10 
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void quickSort(int[], int, int); 
int binarySearch(int[], int); 

int main(void) { 
    srand(time(NULL)); 
    
    int number[MAX] = {0}; 

    int i;
    for(i = 0; i < MAX; i++) { 
        number[i] = rand() % 100; 
    } 

    quickSort(number, 0, MAX-1); 

    printf("數列："); 
    for(i = 0; i < MAX; i++) 
        printf("%d ", number[i]); 

    int find;
    printf("\n輸入尋找對象："); 
    scanf("%d", &find); 

    if((i = binarySearch(number, find)) >= 0) 
        printf("找到數字於索引 %d ", i); 
    else 
        printf("\n找不到指定數"); 
    
    printf("\n"); 

    return 0; 
} 

int binarySearch(int number[], int find) { 
    int low = 0; 
    int upper = MAX - 1; 
    while(low <= upper) { 
        int mid = (low+upper) / 2; 
        if(number[mid] < find) 
            low = mid+1; 
        else if(number[mid] > find) 
            upper = mid - 1; 
        else 
            return mid; 
    } 
    return -1; 
} 

void quickSort(int number[], int left, int right) { 
    if(left < right) { 
        int s = number[(left+right)/2]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(number[++i] < s) ;  // 向右找 
            while(number[--j] > s) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(number[i], number[j]); 
        } 

        quickSort(number, left, i-1);   // 對左邊進行遞迴 
        quickSort(number, j+1, right);  // 對右邊進行遞迴 
    } 
} 
