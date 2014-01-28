#include <stdio.h>

#define M 2
#define N 3
#define K 2

int main()
{
	int A[M][N] = {{1, 2, 3}, {4, 5, 6}};
	int B[N][K] = {{1, 0}, {0, 1}, {1, 0}};
	int C[M][K];
	int i, j, k;
	for(i = 0; i < M; i++)
	{
		for(j = 0; j < K; j++)
		{
			C[i][j] = 0;
			for(k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
	}


	for(i = 0; i < M; i++)
	{
		for(j = 0; j < K; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}
