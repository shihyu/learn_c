#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

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

void EnLinkqueue(linkqueue *lq, datatype x)
{
	linklist p;

	p = (linklist)malloc(sizeof(linknode));
	p->data = x;
	p->next = NULL;
	lq->rear->next = p;
	lq->rear = p;

	return;
}

datatype DeLinkqueue(linkqueue *lq)
{
	linklist p = lq->front;

	lq->front = p->next;
	free(p);

	return lq->front->data;
}

int FirstAdj(int matrix[N][N], int v)
{
	int i;

	for (i=0; i<N; i++)
	{
		if (matrix[v][i] == 1) return i;
	}

	return -1;
}

int NextAdj(int matrix[N][N], int v, int u)
{
	int i;

	for (i=u+1; i<N; i++)
	{
		if (matrix[v][i] == 1) return i;
	}

	return -1;
}

void DFS(int matrix[][N], int v, int visited[])
{
	int u;

	printf("V%d ", v);
	visited[v] = 1;
	u = FirstAdj(matrix, v);
	while (u >= 0)
	{
		if ( ! visited[u] ) DFS(matrix, u, visited);
		u = NextAdj(matrix, v, u);
	}

	return;
}

void BFS(int matrix[][N], int v, int visited[])
{
	int u;
	linkqueue *lq;

	lq = CreateEmptyLinkqueue();
	printf("V%d ", v);
	visited[v] = 1;
	EnLinkqueue(lq, v);
	while ( ! EmptyLinkqueue(lq) )
	{
		v = DeLinkqueue(lq);
		u = FirstAdj(matrix, v);
		while (u >= 0)
		{
			if ( ! visited[u] )
			{
				printf("V%d ", u);
				visited[u] = 1;
				EnLinkqueue(lq, u);
			}
			u = NextAdj(matrix, v, u);
		}
	}

	return;
}

int main()
{
	int matrix[N][N] = {{0}};
	int i, j, visited[N] = {0};

	while ( 1 )
	{
		scanf("%d,%d", &i, &j);
		if (i == j) break;
		matrix[i][j] = matrix[j][i] = 1;
	}

	for (i=0; i<N; i++)
	{
		printf("V%d : ", i);
		for (j=0; j<N; j++)
		{
			if (matrix[i][j]) printf("V%d ", j);
		}
		printf("\n");
	}

	printf("\nDFS : ");
	DFS(matrix, 0, visited);
	printf("\n");

	bzero(visited, sizeof(visited));
	printf("\nBFS : ");
	BFS(matrix, 1, visited);
	printf("\n");

	return 0;
}
