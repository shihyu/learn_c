#include <stdio.h>
#include <stdlib.h>

#define N 64

typedef int datatype;

typedef struct _node_
{
	datatype data;
	struct _node_ *next;
} linkstack;

linkstack *CreateEmptyLinkstack()
{
	linkstack *s;

	s = (linkstack *)malloc(sizeof(linkstack));
	s->next = NULL;

	return s;
}

int EmptyLinkstack(linkstack *s)
{
	return (NULL == s->next);
}

void ClearLinkstack(linkstack *s)
{
	linkstack *p;

	while (s->next != NULL)
	{
		p = s->next;
		s->next = p->next;
		free(p);
	}

	return;
}

void PushStack(linkstack *s, datatype x)
{
	linkstack *p;

	p = (linkstack *)malloc(sizeof(linkstack));
	p->data = x;
	p->next = s->next;
	s->next = p;

	return;
}

datatype PopStack(linkstack *s)
{
	linkstack *p;
	datatype x;

	p = s->next;
	x = p->data;
	s->next = p->next;
	free(p);

	return x;
}

datatype GetTop(linkstack *s)
{
	return (s->next->data);
}

int Pri(char op)
{
	switch ( op )
	{
		case '+' :
		case '-' :
			return 1;
		case '*' :
		case '/' :
			return 2;
	}

	return 0;
}

int Compute(int op1, int op2, char op)
{
	switch ( op )
	{
	case '+' :
		return op1 + op2;
	case '-' :
		return op1 - op2;
	case '*' :
		return op1 * op2;
	case '/' :
		return op1 / op2;
	}

	return 0;
}

void del_op(linkstack *operator, linkstack *operand, char op)
{
	int op1, op2, result;

	while ( ! EmptyLinkstack(operator) && (Pri(op) <= Pri(GetTop(operator))) )
	{
		op2 = PopStack(operand);
		op1 = PopStack(operand);
		result = Compute(op1, op2, PopStack(operator));
		PushStack(operand , result);
	}
	PushStack(operator, op);

	return;
}

int main()
{
	int sum, op1, op2, result;
	char str[N], *p = str;
	linkstack *operator, *operand;

	operator = CreateEmptyLinkstack();
	operand = CreateEmptyLinkstack();

	scanf("%s", str);
	while ( *p )
	{
		if ((*p >= '0') && (*p <= '9'))
		{
			sum = 0;
			while ((*p >= '0') && (*p <= '9'))
			{
				sum = 10*sum + *p - '0';
				p++;
			}
			PushStack(operand, sum);
		}
		else
		{
			del_op(operator, operand, *p);
			p++;
		}
	}

	while ( ! EmptyLinkstack(operator) )
	{
		op2 = PopStack(operand);
		op1 = PopStack(operand);
		result = Compute(op1, op2, PopStack(operator));
		PushStack(operand , result);
	}
	printf("%s = %d\n", str, PopStack(operand));

	return 0;
}
