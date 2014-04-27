#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10
#define M 5
#define N 3

void show(int row, int col, int ar[row][col]) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", ar[i][j]);
        }

        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
	int matrix_a[M][N];
	int matrix_b[N][M];

	srand(time(NULL));
	
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			matrix_a[i][j] = rand() % RANGE;
		}
	}

	show(M, N, matrix_a);

	#if 0
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", matrix_a[i][j]);
		}
		printf("\n");
	}
	#endif

	printf("\n");

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			matrix_b[j][i] = matrix_a[i][j];
		}
	}

	show(N, M, matrix_b);
	#if 0
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ", matrix_b[i][j]);
		}
		printf("\n");
	}
	#endif
	



	return 0;

}