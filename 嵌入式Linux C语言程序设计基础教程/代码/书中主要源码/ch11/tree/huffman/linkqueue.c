#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

linkqueue *CreateEmptyLinkqueue()
{
	linkqueue *q;

	q = (linkqueue *)malloc(sizeof(linkqueue));
	q->front = q->rear = (listnode *)malloc(sizeof(listnode));
	q->front->next = NULL;

	return q;
}

int EmptyLinkqueue(linkqueue *q)
{
	return (q->front == q->rear);
}

void EnQueue(linkqueue *q, datatype r)
{
	listnode *p;

	p = (listnode *)malloc(sizeof(listnode));
	p->data = r;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	return;
}

datatype DeQueue(linkqueue *q)
{
	listnode *p;

	p = q->front;
	q->front = p->next;
	free(p);

	return q->front->data;
}

