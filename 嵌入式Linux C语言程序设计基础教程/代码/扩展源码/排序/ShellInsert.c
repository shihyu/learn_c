#include <stdio.h>

#define SIZE 50

typedef struct
{
	int data[SIZE];
	int len;
}SqList;

void ShellInsert( SqList* l, int d )
{
	int i =0;	
	int t = 0;
	int j = 0;
	for( i = d; i < l->len; i++ )
	{
		t = l->data[i];
		for ( j = i - d; j >= 0; j = j - d )
		{
			if( t < l->data[j])
			{
				l->data[j+d] = l->data[j];
			}
			else
			{
				break;
			}
		}		
		l->data[j+d] = t;
	}
}

void ShellSort( SqList* l, int* d, int n )
{
	int i = 0;
	for( i = 0; i < n; i++)
	{
		ShellInsert( l, d[i] );
	}
}

void BubbleSort( SqList* l)
{
	int i = 0;
	int j = 0;
	int t = 0;
	int index = 0;
	for( i = 0; i < l->len-1; i++ )
	{
		index = 0;
		for( j = 0; j < l->len-1-i; j++ )
		{
			if( l->data[index] < l->data[j+1] )//j=n-2
			{
				index = j+1;
			}
		}
		//index len-1-i

		t = l->data[index];
		l->data[index] = l->data[l->len-1-i];
		l->data[l->len-1-i] = t;
	}

}

int Partition( SqList* l, int low, int high )
{
	int t = 0;
	t = l->data[low];
	while( low < high )
	{
		while( low < high && l->data[high] >= t) 
		{
			high--;
		}
		l->data[low] = l->data[high];
		while( low < high && l->data[low] <= t)
		{
			low++;
		}
		l->data[high] = l->data[low];
	}
	l->data[low] = t;
	return low;
}

void QSort( SqList* l, int low, int high )
{
	if( low >= high )
	{
		return;
	}
	int pivotloc = 0;
	pivotloc = Partition( l, low, high );
	QSort( l, low, pivotloc-1 );
	QSort( l, pivotloc+1, high );
}

void QuitSort( SqList* l )
{
	QSort( l, 0, l->len-1 );
}

int main()
{
	SqList l;
	l.len = 10;
	int i = 0;
	for ( i = 0; i < 10; i++ )
	{
		l.data[i] = 15-i;
	}

	//InsertSort( &l );
	
	//int d[2] = { 3, 1 };
	//ShellSort( &l, d, 2 );
	//BubbleSort( &l );
	QuitSort( &l );
	for( i = 0; i < 10; i++)
	{
		printf( "%d\n", l.data[i] );
	}	

	return 0;
}
