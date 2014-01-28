typedef struct node
{
   int data;
   struct node *next;
} linknode, *linklist;

typedef struct 
{
   linklist front;
   linklist rear;
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

void EnQueue(linkqueue *lq, int value)
{
   lq->rear->next = (linklist)malloc(sizeof(linknode));
   lq->rear = lq->rear->next;
   lq->rear->data = value;
   lq->rear->next = NULL;

   return;
}   


int DeQueue(linkqueue *lq)
{
   linklist r;   

   r = lq->front;
   lq->front = r->next;
   free(r);
   
   return lq->front->data;
}


