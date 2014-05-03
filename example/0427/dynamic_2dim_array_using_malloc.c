#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define RANGE 100


void show(int** arr, int row, int col) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d\t", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main(void) 
{ 
    int numRows, numCols; 
    int **arrayPtr; 
    int i, j;

    printf("Enter values for numRows and numCols\n");   
    scanf("%d",&numRows); 
    scanf("%d",&numCols); 

    /* Create space for first array (array of pointers to each row). */ 
    arrayPtr = (int **) malloc(numRows*sizeof(int*)); //配置雙重指標指向(int*)型態 * numRows個  
    for(i=0 ; i<numRows ; ++i)  
    { 
        arrayPtr[i] = (int*) malloc(numCols*sizeof(int)); //以for迴圈配置n個一重指標指向int空間 
    } 
    
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            arrayPtr[i][j] = rand() % RANGE;
        }
    }

    show(arrayPtr, numRows, numCols);
   
    // do something with arrayPtr[i][j] 
    for( i=0 ; i<numRows ; ++i) 
    { 
        free(arrayPtr[i]) ;  // 以迴圈釋放n個一重指標指向的空間 
    } 

    free(arrayPtr) ; //釋放雙重指標 
    return 0;
}
