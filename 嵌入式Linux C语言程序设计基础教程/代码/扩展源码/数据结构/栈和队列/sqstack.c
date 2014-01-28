#include <stdio.h>
#include <stdlib.h>

#define  N  8

typedef int datatype;

typedef struct
{
	datatype data[N];
	int top;
} sqstack;

sqstack *CreateEmptySqstack()
{
	sqstack *sq;

	sq = (sqstack *)malloc(sizeof(sqstack));
	sq->top = -1;

	return sq;
}

int EmptySqstack(sqstack *sq)
{
	return (-1 == sq->top);
}

int FullSqstack(sqstack *sq)
{
	return (N-1 == sq->top);
}

void ClearSqstack(sqstack *sq)
{
	sq->top = -1;

	return;
}

void PushStack(sqstack *sq, datatype x)
{
	sq->top++;
	sq->data[sq->top] = x;

	return;
}

datatype PopStack(sqstack *sq)
{
	return sq->data[sq->top--];
}

datatype GetTop(sqstack *sq)
{
	return sq->data[sq->top];
}

int main()
{
	sqstack *sq;
	int n;

	sq = CreateEmptySqstack();
	printf("input n : ");
	scanf("%d", &n);
	while ( 1 )
	{
		PushStack(sq, n%16);
		n /= 16;
		if (n == 0) break;
	}
	while ( ! EmptySqstack(sq) )
	{
		n = PopStack(sq);
		if (n < 10) printf("%d", n);
		else printf("%c", n-10+'a');
	}

	printf("\n");

	return 0;
}
