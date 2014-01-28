#include <stdio.h>

#define N 6
#define M (1<<20)

int main()
{
	int i, j, startnode, count = 0, min, path;
	int s[N] = {0}, dist[N];
	int array[N][N] = {{ 0, 20, 15,  M,  M,  M},
		               { 2,  0,  4,  M, 10, 30},
					   { M,  M,  0,  M,  M, 10},
					   { M,  M,  M,  0,  M,  M},
					   { M,  M,  M, 15,  0, 10},
					   { M,  M,  M,  4,  M,  0}};

	startnode = 0;
	s[startnode] = 1;
	for (i=0; i<N; i++)
	{
		dist[i] = array[startnode][i];
	}
	count = 1;
	while (count < N-1)
	{
		path = M;
		for (i=0; i<N; i++)
		{
			if ((s[i] == 0) && (dist[i] < path))
			{
				path = dist[i];
				min = i;
			}
		}
		s[min] = 1;
		for (i=0; i<N; i++)
		{
			if ((s[i] == 0) && (dist[i] > dist[min]+array[min][i]))
			{
				dist[i] = dist[min] + array[min][i];
			}
		}
		count++;
	}

	for (i=0; i<N; i++)
	{
		printf("V%d -> V%d : %d\n", startnode, i, dist[i]);
	}

	return 0;
}
