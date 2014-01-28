#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct _node_
{
	datatype data;
	struct _node_ *next;
} linknode, *linklist;

typedef struct
{
	linklist front, rear;
} linkqueue;

linkqueue *CreateEmptyLinkqueue()
{
	linkqueue *lq;

	lq = (linkqueue *)malloc(sizeof(linkqueue));
	lq->front = lq->rear = (linklist)malloc(sizeof(linknode));
	lq->front->next = NULL;

	return lq;
}

int EmptyLinkqueue(linkqueue *lq)
{
	return (lq->front == lq->rear);
}

void EnQueue(linkqueue *lq, datatype x)
{
	linklist p;

	p = (linklist)malloc(sizeof(linknode));
	p->data = x;
	p->next = NULL;
	lq->rear->next = p;
	lq->rear = p;

	return;
}

datatype DeQueue(linkqueue *lq)
{
	linklist p = lq->front;

	lq->front = p->next;
	free(p);

	return lq->front->data;
}

void ClearLinkqueue(linkqueue *lq)
{
	while ( ! EmptyLinkqueue(lq) )
	{
		DeQueue(lq);
	}

	return;
}

int main()
{
	int i;
	linkqueue *lq;

	lq = CreateEmptyLinkqueue();
	for (i=1; i<=6; i++)
	{
		EnQueue(lq, i);
	}
	
	while ( ! EmptyLinkqueue(lq) )
	{
		printf("%d ", DeQueue(lq));
	}
	printf("\n");

	return 0;
}
