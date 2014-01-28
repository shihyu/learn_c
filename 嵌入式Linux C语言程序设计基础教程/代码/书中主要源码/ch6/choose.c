#include <stdio.h>

#define N 10 
int main(int argc,char **argv) 
{ 
    int a[N], i, j, r, t; 

    printf("please input %d numbers\n",N); 
    for (i = 0; i < N; i++) 
        scanf("%d",&a[i]); 

    for (i = 0; i < N-1; i++) 
    {
        r = i; 
        for (j = i+1; j < N; j++) 
            if (a[j] < a[r]) 
                r = j; 
        if(r != i) 
        { 
            t = a[r]; 
            a[r] = a[i]; 
            a[i] = t; 
        } 
    } 

    printf("the array after sort:\n"); 
    for (i = 0; i < N; i++) 
        printf("%5d",a[i]); 
    printf("\n"); 

    return 0;
} 
