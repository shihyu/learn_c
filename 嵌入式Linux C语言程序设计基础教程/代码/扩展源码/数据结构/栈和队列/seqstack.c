#include <stdio.h>
#include <stdlib.h>

#define  N  8

typedef int datatype;

typedef struct
{
	datatype data[N];
	int top;
} seqstack;

seqstack *CreateEmptySeqstack()
{
	seqstack *sq;

	sq = (seqstack *)malloc(sizeof(seqstack));
	sq->top = -1;

	return sq;
}

int EmptySeqstack(seqstack *sq)
{
	return (-1 == sq->top);
}

int FullSeqstack(seqstack *sq)
{
	return (N-1 == sq->top);
}

void ClearSeqstack(seqstack *sq)
{
	sq->top = -1;

	return;
}

void PushSeqstack(seqstack *sq, datatype x)
{
	sq->top++;
	sq->data[sq->top] = x;

	return;
}

datatype PopSeqstack(seqstack *sq)
{
	return sq->data[sq->top--];
}

datatype GetTop(seqstack *sq)
{
	return sq->data[sq->top];
}

int main()
{
	seqstack *sq;
	int n;

	sq = CreateEmptySeqstack();
	printf("input n : ");
	scanf("%d", &n);
	while ( 1 )
	{
		PushSeqstack(sq, n%16);
		n /= 16;
		if (n == 0) break;
	}
	while ( ! EmptySeqstack(sq) )
	{
		n = PopSeqstack(sq);
		if (n < 10) printf("%d", n);
		else printf("%c", n-10+'a');
	}

	printf("\n");

	return 0;
}
