#include <stdio.h>

#define SIZE 50

typedef struct
{
	int data[SIZE];
	int len;
}SqList;

void InsertSort( SqList* l )
{
	int i = 0;
	int j = 0;
	int t = 0;
	for( i = 1; i < l->len; i++ )
	{
		t = l->data[i];
		for( j = i-1; j >= 0; j-- )
		{
			if( t < l->data[j] )
			{
				l->data[j+1] = l->data[j];	
			}
			else
			{
				break;
			}
		}
		l->data[j+1] = t;
	}
}

void HeapAdjust( SqList* l, int s, int m )
{
	int t = 0;
	t = l->data[s];
	int i = 0;
	for( i = 2*s+1; i <= m; i = 2*i+1)
	{
		if( i < m && l->data[i] > l->data[i+1] ) ++i;
		if( t < l->data[i]) break;
		l->data[s] = l->data[i];
		s = i;
	}
	l->data[s] = t;
}

void HeapSort( SqList* l)
{
	int i = 0;
	int t = 0;
	for( i = l->len/2 -1; i >= 0; i-- )
	{
		HeapAdjust( l, i, l->len-1 );
	}
	printf("%d  ",l->data[0]);
	for( i = l->len-1; i > 0; i-- )
	{
		t = l->data[0];
		l->data[0] = l->data[i];
		l->data[i] = t;
		HeapAdjust( l, 0, i-1);
		printf("%d  ",l->data[0]);
	}
	printf("\n");


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
	HeapSort( &l );

	for( i = 0; i < 10; i++)
	{
//		printf( "%d\n", l.data[i] );
	}	

	return 0;
}
