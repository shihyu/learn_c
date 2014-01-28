#define N 64

typedef struct
{
   int data[N];
   int top;
} sqstack;

sqstack *CreateEmptySqstack()
{
	sqstack *s;

	s = (sqstack *)malloc(sizeof(sqstack));
	s->top = -1;

	return s;
}

void ClearSqstack(sqstack *s)
{
   s->top = -1;
   return;
}

int EmptySqstack(sqstack *s)
{
   return (-1 == s->top);
}

void PushStack(sqstack *s, int value)
{
   s->data[++s->top] = value;
   return;
} 

int PopStack(sqstack *s)
{
   return s->data[s->top--];  
}

int GetTop(sqstack *s)
{
   return s->data[s->top];
}
