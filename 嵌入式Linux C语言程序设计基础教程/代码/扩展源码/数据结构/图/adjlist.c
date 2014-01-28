#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct _node_
{
	int vertex;
	struct _node_ *next;
} linknode, *linklist;

void AddEdge(linklist h, int vertex)
{
	linklist p;

	while ((h->next != NULL) && (h->next->vertex < vertex)) h = h->next;
	p = (linklist)malloc(sizeof(linknode));
	p->vertex = vertex;
	p->next = h->next;
	h->next = p;

	return;
}

int FirstAdj(linknode s[], int v)
{
	return s[v].next->vertex;
}

int NextAdj(linknode s[], int v, int u)
{
	linklist p;

	p = s[v].next;
	while (p->vertex != u) p = p->next;
	p = p->next;

	return (p == NULL ? -1 : p->vertex);
}

int main()
{
	linknode s[N] = {{0, NULL}};
	int i, j;
	linklist p;

	while ( 1 )
	{
		scanf("%d,%d", &i, &j);
		if (i == j) break;
		AddEdge(s+i, j);
		AddEdge(s+j, i);
	}

	for (i=0; i<N; i++)
	{
		printf("V%d : ", i);
		p = s[i].next;
		while (p != NULL)
		{
			printf("V%d ", p->vertex);
			p = p->next;
		}
		printf("\n");
	}
	
	return 0;
}
