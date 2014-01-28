#include <stdio.h>
#include <stdlib.h>

//typedef int datatype;

typedef struct _bitree_
{
	int data;
	struct _bitree_ *lchild, *rchild;
} bitree;

typedef bitree *datatype;

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

bitree *CreateBitree(int i, int n)
{
	bitree *root;

	root = (bitree *)malloc(sizeof(bitree));
	root->data = i;
	if (2*i <= n) root->lchild = CreateBitree(2*i, n);
	else root->lchild = NULL;
	
	if (2*i+1 <= n) root->rchild = CreateBitree(2*i+1, n);
	else root->rchild = NULL;

	return root;
}

void PreOrder(bitree *root)
{
	if (NULL == root) return;
	printf("%d ", root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);

	return;
}

void InOrder(bitree *root)
{
	if (NULL == root) return;
	InOrder(root->lchild);
	printf("%d ", root->data);
	InOrder(root->rchild);

	return;
}

void PostOrder(bitree *root)
{
	if (NULL == root) return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	printf("%d ", root->data);

	return;
}

void NoOrder(bitree *root)
{
	linkqueue *lq;

	lq = CreateEmptyLinkqueue();
	EnQueue(lq, root);
	while ( ! EmptyLinkqueue(lq) )
	{
		root = DeQueue(lq);
		printf("%d ", root->data);
		if (root->lchild != NULL) EnQueue(lq, root->lchild);
		if (root->rchild != NULL) EnQueue(lq, root->rchild);
	}

	return;
}

int main()
{
	bitree *root;

	root = CreateBitree(1, 10);
	
	printf("PreOrder  : ");
	PreOrder(root);
	printf("\n");

	printf("InOrder   : ");
	InOrder(root);
	printf("\n");

	printf("PostOrder : ");
	PostOrder(root);
	printf("\n");

	printf("NoOrder   : ");
	NoOrder(root);
	printf("\n");

	return 0;
}
