#include <stdio.h>

#define SIZE 10

typedef struct 
{
	int a[SIZE];
	int len;
}SqList;

void BubbleSort( SqList* l )
{
	int i = 0;
	int j = 0;
	int t = 0;
	int index = 0;
	for( i = 0; i < l->len-1; i++ )
	{
		index = 0;
		for( j = 0; j < l->len-1-i ; j++ )
		{
			if(l->a[index] < l->a[j+1])
			{
				index = j+1;						
			}
		}
		//a[index] a[n-1-i]
		t = l->a[index];
		l->a[index] = l->a[l->len-1-i];
		l->a[l->len-1-i] = t;
	}
}

void BubbleSort2( SqList* l )
{
	int i = 0;
	int j = 0;
	int t = 0;
	int flag = 0;
	int index = 0;
	for( i = 0; i < l->len-1; i++ )
	{
		index = 0;
		flag = 0;
		for( j = 0; j < l->len-1-i ; j++ )
		{
			if(l->a[j] > l->a[j+1])
			{
				flag = 1;
			}
			if( l->a[index] < l->a[j+1] )
			{	
				index = j+1;
			}
		}
		if( flag == 0)
		{
			break;
		}
		//a[index] a[n-1-i]
		t = l->a[index];
		l->a[index] = l->a[l->len-1-i];
		l->a[l->len-1-i] = t;
	}
}


int BiSearch( SqList* l, int data )
{
	int low = 0;
	int high = 0;
	int mid = 0;

	high = l->len-1;
	mid = ( low + high ) / 2;
	while( low <= high )
	{
		if( data < l->a[mid] ) 
		{	
			high = mid - 1;	
			mid = ( low + high ) / 2;
			
		}
		else if( data > l->a[mid])
		{
			low = mid + 1;
			mid = ( low + high ) / 2;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int Partition( SqList* l, int low, int high )
{
	int t = 0;
	t = l->a[low];
	while( low < high )
	{
		while( low < high && t < l->a[high])
		{
			high--;
		}
		l->a[low] = l->a[high];
		while( low < high && t > l->a[low] )
		{
			low++;
		}
		l->a[high] = l->a[low];
	}	
	l->a[low] = t;

	return low;
}

void QuickSort( SqList* l, int low, int high )
{
	if( low >=high )
	{
		return;
	}
	int t = 0;
	t = Partition( l, low, high );
	QuickSort( l, low, t-1 );
	QuickSort( l, t+1, high );
}

void QSort( SqList* l )
{
	int low = 0;
	int high = l->len-1;
	QuickSort( l, low, high );
}

void InsertSort( SqList* l )
{
	int i = 0;
	int j = 0;	
	int t = 0;

	for( i = 1; i < l->len; i++ )
	{
		t = l->a[i];
		for( j = i-1; j >= 0; j-- )
		{
			if( t < l->a[j] )
			{
				l->a[j+1] = l->a[j];
			}
			else
			{	
				break;
			}
		}
		l->a[j+1] = t;
	}
}

int biInsertSort(int* data, int n)
{
	if ( data == NULL || n < 2)
	{
		return -1;
	}

	int t = 0;
	int j = 0;
	int low = 0;
	int high = 0;
	int mid = 0;

	//t < data[mid]; high = mid-1;
	//t > data[mid]; low = mid+1;
	//while( low high)

	for (int i = 1; i < n; i++)
	{
		t = data[i];
		low = 0;
		high = i-1;
		mid = (low+high)/2;

		while (low <= high)
		{
			if ( t < data[mid] )
			{
				high = mid - 1;
				mid = (low+high)/2;
			}
			else
			{
				low = mid + 1;
				mid = (low+high)/2;
			}
		}

		for (int j = i-1; j >= high ; j--)
		{
			data[j+1] = data[j];
		}
		data[high+1] = t;
	}
	return 1;
}


void ShellInsert( SqList* l, int d, int n )
{
	int i = 0;
	int j = 0;	
	int t = 0;
	for( i = d; i < l->len; i=i+1 )
	{
		t = l->a[i];
		for( j = i-d; j >= 0; j=j-d )
		{
			if ( t < l->a[j])
			{	
				l->a[j+d] = l->a[j];
			}
			else
			{
				break;
			}
		}
		l->a[j+d] = t;
	}
}

void ShellSort( SqList* l)
{
	int d[3]={ 5, 3, 1};
	int i = 0;
	for( i = 0; i < 3; i++)
	{
		ShellInsert( l, d[i], 3 );
	}
}

int main()
{
	SqList l;	
	int i = 0;
	for( i = 0; i < 10; i++ )
	{
		l.a[i] = 15-i;
	}
	l.len = 10;	

	//BubbleSort2( &l );
	//QSort( &l );
	//InsertSort( &l );
	ShellSort( &l );
	for( i = 0; i < l.len; i++ )
	{
		printf("%d  ", l.a[i] );
	}
	printf("\n");
	/*int ret = 0;
	ret = BiSearch( &l, 10 );
	printf("%d\n", ret );
	*/
	return 0;
}

