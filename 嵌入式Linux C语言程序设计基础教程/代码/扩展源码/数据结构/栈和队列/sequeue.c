#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int datatype;

typedef struct
{
	datatype data[N];
	int front, rear;
} sequeue;

sequeue *CreateEmptySequeue()
{
	sequeue *sq;

	sq = (sequeue *)malloc(sizeof(sequeue));
	sq->front = sq->rear = 0;

	return sq;
}

int EmptySequeue(sequeue *sq)
{
	return (sq->front == sq->rear);
}

int FullSequeue(sequeue *sq)
{
	return ((sq->rear + 1) % N == sq->front);
}

void ClearSequeue(sequeue *sq)
{
	sq->front = sq->rear;

	return;
}

void EnQueue(sequeue *sq, datatype x)
{
	sq->rear = (sq->rear + 1) % N;
	sq->data[sq->rear] = x;

	return;
}

datatype DeQueue(sequeue *sq)
{
	sq->front = (sq->front + 1) % N;

	return sq->data[sq->front];
}

int main()
{
	int i;
	sequeue *sq;

	sq = CreateEmptySequeue();

	for (i=1; i<8; i++)
	{
		if ( ! FullSequeue(sq) ) EnQueue(sq, i);
		else printf("queue is full\n");
	}

	while ( ! EmptySequeue(sq) )
	{
		printf("%d ", DeQueue(sq));
	}
	printf("\n");

	return 0;
}
