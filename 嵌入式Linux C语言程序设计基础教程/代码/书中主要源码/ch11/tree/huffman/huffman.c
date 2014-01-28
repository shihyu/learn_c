#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue.h"

bitree *CreateEmptyList()
{
	bitree *h;

	h = (bitree *)malloc(sizeof(bitree));
	h->next = h->lchild = h->rchild = NULL;

	return h;
}

void InsertList(bitree *h, bitree *q)
{
	while (h->next && (h->next->weight < q->weight))
	{
		h = h->next;
	}
	q->next = h->next;
	h->next = q;

	return;
}

void VisitList(bitree *h)
{
	h = h->next;
	while ( h )
	{
		printf("%d ", h->weight);
		h = h->next;
	}
	printf("\n");

	return;
}

void CreateHaffmanTree(bitree *h)
{
	bitree *p;

	while (h->next && h->next->next)
	{
		p = (bitree *)malloc(sizeof(bitree));
		p->lchild = h->next;
		p->rchild = h->next->next;
		p->weight = p->lchild->weight + p->rchild->weight;
		h->next = p->rchild->next;
		InsertList(h, p);
	}

	return;
}

void NoOrder(bitree *root)
{
	bitree *p;
	linkqueue *queue;

	queue = CreateEmptyLinkqueue();
	EnQueue(queue, root);
	while ( !EmptyLinkqueue(queue) )
	{
		p = DeQueue(queue);
		if ((p->lchild == NULL) && (p->rchild == NULL))
		{	
			printf("%c[%2d] : %s\n", p->ch, p->weight, p->code);
			continue;
		}
		if (p->lchild) 
		{
			strcpy(p->lchild->code, p->code);
			strcat(p->lchild->code, "0");
			EnQueue(queue, p->lchild);
		}
		if (p->rchild) 
		{
			strcpy(p->rchild->code, p->code);
			strcat(p->rchild->code, "1");
			EnQueue(queue, p->rchild);
		}
	}

	return;
}

int main(int argc, char *argv[])
{
	int i, value;
	char ch;
	bitree *h, *p;

	h = CreateEmptyList();

	while (scanf("%c %d\n", &ch, &value) == 2)
	{
		p = (bitree *)malloc(sizeof(bitree));
		p->ch = ch;
		p->weight = value;
		p->code[0] = '\0';
		p->lchild = p->rchild = NULL;
		InsertList(h, p);
	}

	VisitList(h);
	CreateHaffmanTree(h);
	NoOrder(h->next);

	return 0;
}
