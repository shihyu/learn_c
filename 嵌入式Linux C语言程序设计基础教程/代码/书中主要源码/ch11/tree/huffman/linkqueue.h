typedef struct _tree_
{
	char ch;
	int weight;
	char code[10];
	struct _tree_ *next, *lchild, *rchild;
} bitree;

typedef bitree *datatype;

typedef struct _node_
{
	datatype data;
	struct _node_ *next;
} listnode;

typedef struct
{
	listnode *front;
	listnode *rear;
} linkqueue;

linkqueue *CreateEmptyLinkqueue();

int EmptyLinkqueue(linkqueue *q);

void EnQueue(linkqueue *q, datatype x);

datatype DeQueue(linkqueue *q);

