#include <stdio.h>

#define M 2
#define N 3
#define K 2

int main(int argc, char *argv[])
{
    int A[M][N] = {{1, 0, 1}, {1, 1, 0}};
    int B[N][K] = {{1, 0}, {1, 0},{0, 1}}; 
    int C[M][K], i, j, k;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < K; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];

            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
