/*
ㄢ俱计が传ノC++ユ把σ
*/

#include  <stdio.h>

/*---nx籔nyンぇが传---*/
void swap(int& nx, int& ny)
{
     int  temp = nx;
     nx = ny;
     ny = temp;
}

int main(void)
{
    int	 na, nb;

    puts("叫块ㄢ俱计");
    printf("俱计A");       scanf("%d", &na);
    printf("俱计B");       scanf("%d", &nb);

    swap(na, nb);

    puts("ㄢユ传");
    printf("俱计A%d\n", na);
    printf("俱计B%d\n", nb);
    
    return (0);
}
