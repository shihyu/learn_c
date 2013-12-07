#include <stdio.h>
#include <stdlib.h>

int Sum = 0;
const int qty;

void Compute_Avg(void);

int main(void) {
    float Avg;
    int i;
    int A[5] = {10, 20, 30, 40, 50};

    for (i = 0; i < qty; i++) {
        Sum = Sum + A[i];
    }

    Compute_Avg();
    printf("Sum=%d\n", Sum);
    printf("Avg=%f\n", Avg);
}
