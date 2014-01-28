#include <stdio.h>

#define N 10 

int main(int argc,char **argv) 
{ 
    int a[N], i, j, t; 

    printf("please input %d numbers\n",N); 

    for (i = 0; i < N; i++) 
        scanf("%d",&a[i]); 

    for (i = 0; i < N-1; i++) 
        for (j = 0; j < N-1-i; j++) 
        { 
            if (a[j] > a[j+1]) 
            { 
                t = a[j]; 
                a[j] = a[j+1]; 
                a[j+1] = t; 
            } 
        } 

    printf("the array after sort:\n"); 
    for (i = 0; i < N; i++) 
        printf("%5d\n",a[i]); 

    return 0;
} 

