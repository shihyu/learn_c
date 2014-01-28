#include <stdio.h>
#include <stdlib.h>

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

void PushLinkstack(linkstack *s, datatype x)
{
	linkstack *p;

	p = (linkstack *)malloc(sizeof(linkstack));
	p->data = x;
	p->next = s->next;
	s->next = p;

	return;
}

datatype PopLinkstack(linkstack *s)
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
