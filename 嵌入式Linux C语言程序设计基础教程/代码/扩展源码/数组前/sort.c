#include <stdio.h>

#define INT_SIZE 10
int main()
{
	int arr[INT_SIZE];
	int i = 0, j, min, temp;
	
	for(; i < INT_SIZE; i++)
	{
		arr[i] = 10 - i;
		printf("%d  ", arr[i]);
	}
	printf("\n");

	for(i = 0; i < INT_SIZE - 1; i++)//
	{
		min = i ;

		for(j = i + 1; j < INT_SIZE; j++)// i+1 i+2 .. INT_SIZE-1
		{
			if(arr[min] > arr[j])
				min = j;
		}
		//i min

		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
	int k = 0;
	for(k = 0; k < INT_SIZE; k++)
	{
		printf("%d  ", arr[k]);
	}
	printf("\n");
	

	return 0;
}
